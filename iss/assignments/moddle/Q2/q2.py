import json
import csv
import requests

github_url = "https://raw.githubusercontent.com/sharmadhiraj/free-json-datasets/master/datasets/"

file_names = [
    "nepse-listed-companies-2021.json",
    "nobel-prize-winners-by-year.json",
    "oscar-best-picture-award-winners.json",
    "premier-league-points-table.json",
    "world-population-by-country-2020.json"
]

merged_data = []

# Fetch and merge all JSON data
for file_name in file_names:
    url = github_url + file_name
    response = requests.get(url)
    if response.status_code == 200:
        data = json.loads(response.text)
        if isinstance(data, list):
            merged_data.extend(data)  # Merge lists
        else:
            merged_data.append(data)  # Append single dictionary
    else:
        print(f"Failed to fetch {file_name}")

# Part (b): Extract and print all keys (including nested ones)
def extract_keys(data, parent_key=""):
    keys = []
    if isinstance(data, dict):
        for key, value in data.items():
            new_key = f"{parent_key}.{key}" if parent_key else key
            keys.append(new_key)
            keys.extend(extract_keys(value, new_key))  
    elif isinstance(data, list):
        for item in data:
            keys.extend(extract_keys(item, parent_key))  
    return keys

all_keys = extract_keys(merged_data)

# Restore print statement for part (b)
print(set(all_keys))  # Print only unique keys to the terminal as required in the question

# Part (c): Convert nested JSON to a CSV-compatible format
def flatten_dict(d, parent_key=""):
    items = []
    if isinstance(d, dict):
        for k, v in d.items():
            new_key = f"{parent_key}.{k}" if parent_key else k
            items.extend(flatten_dict(v, new_key).items())
    elif isinstance(d, list):
        for i, v in enumerate(d):
            new_key = f"{parent_key}[{i}]"
            items.extend(flatten_dict(v, new_key).items())
    else:
        items.append((parent_key, d))
    return dict(items)

# Flatten all JSON records
flattened_data = [flatten_dict(entry) for entry in merged_data]

# Extract all unique column keys
all_keys = sorted(set(k for d in flattened_data for k in d.keys()))

# Write CSV file
csv_file = "output.csv"
with open(csv_file, "w", newline="", encoding="utf-8") as csvfile:
    writer = csv.DictWriter(csvfile, fieldnames=all_keys)
    
    writer.writeheader()
    for row in flattened_data:
        writer.writerow(row)