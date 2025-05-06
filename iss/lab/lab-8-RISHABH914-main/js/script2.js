document.addEventListener("DOMContentLoaded", function () {
    let taskInput = document.getElementById("taskInput");
    let addTaskBtn = document.getElementById("addTaskBtn");
    let taskList = document.getElementById("taskList");

    let taskCounter = document.createElement("p");
    taskCounter.textContent = "No tasks remaining";
    document.querySelector(".todo-container").appendChild(taskCounter);

    let tasks = []; // Array to store tasks

    function updateUI() {
        taskList.innerHTML = "";
        let remaining = 0; 

        for (let i = 0; i < tasks.length; i++) {
            let li = document.createElement("li");
            li.textContent = tasks[i].text;

            if (tasks[i].done) {
                li.classList.add("completed");
            } else {
                remaining++; // Count uncompleted tasks
            }

            li.addEventListener("click", function () {
                tasks[i].done = !tasks[i].done;
                updateUI();
            });

            let delBtn = document.createElement("button");
            delBtn.textContent = "Delete";
            delBtn.classList.add("delete-btn");
            delBtn.addEventListener("click", function (e) {
                e.stopPropagation();
                tasks.splice(i, 1);
                updateUI();
            });

            li.appendChild(delBtn);
            taskList.appendChild(li);
        }

        if (remaining === 0) {
            taskCounter.textContent = "No tasks remaining";
        } else {
            taskCounter.textContent = remaining === 1 ? "1 task remaining" : remaining + " tasks remaining";
        }
    }

    addTaskBtn.addEventListener("click", function () {
        let taskText = taskInput.value.trim();
        if (taskText !== "") {
            tasks.push({ text: taskText, done: false });
            taskInput.value = "";
            updateUI();
        }
    });

    taskInput.addEventListener("keypress", function (event) {
        if (event.key === "Enter") {
            addTaskBtn.click();
        }
    });

    updateUI(); // Initialize UI
});
