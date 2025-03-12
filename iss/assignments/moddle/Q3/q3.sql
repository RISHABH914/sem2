-- Write all sql commands here, write comments for all of them too

--part 1

-- for creating the database
use iss_assignment;

-- for cerating the table
create table data_temp(                 -- declaring the fields and their data type for table creation
    year int,
    min_temp decimal(5,2),
    min_place varchar(255),
    min_date date,
    max_temp decimal(5,2),
    max_place varchar(255),
    max_date date
)

--inserting the data into the tabel
LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 9.2/Uploads/32_14HottestColdPlaces20092021.csv'
INTO TABLE data_temp
FIELDS TERMINATED BY ','  
ENCLOSED BY '"'
LINES TERMINATED BY '\n'
IGNORE 1 LINES;

-- providing the insights

-- first is finding average max and min temperature across complete data
    select avg(max_temp) as average_max,avg(min_temp) as average_min 
    from data_temp

-- second is finding max and min temperature in all time (whose data is available)
    select year,max_date,max_temp,max_place from data_temp
    order by max_temp desc
    limit 1                             -- finding max temp 

    select year,min_date,min_temp,min_place from data_temp
    order by max_temp desc
    limit 1                             -- finding min temp

-- third is finding the area which had max and min temp for the most time
    select max_place
    from data_temp
    group by max_place 
    order by count(*) desc
    limit 1;                            -- finding the place which had max_temp for maixmum no of times

    select min_place
    from data_temp
    group by min_place 
    order by count(*) desc
    limit 1;                            --finding the place which had min_temp for maximum no of times


--fourth is finding the year with maximum and minimum temperature difference between max and min temperature of the year
    select year,max_temp-min_temp as temp_range
    from data_temp
    order by temp_range desc
    limit 1                             --finding the year with maximum temperature difference between max and min temperature of the year

    select year,max_temp-min_temp as temp_range
    from data_temp
    order by temp_range asc
    limit 1                             --finding the year with minimum temperature difference between max and min temperature of the year


--fifth is finding the average variation
    select avg(max_temp-min_temp) as avg_variation
    from data_temp