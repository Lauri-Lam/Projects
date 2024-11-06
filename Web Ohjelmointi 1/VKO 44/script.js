const todoForm = document.getElementById('todoForm');
const taskNameInput = document.getElementById('taskName');
const priorityInput = document.getElementById('priority');
const dueDateInput = document.getElementById('dueDate');
const todoTable = document.getElementById('todoTable').getElementsByTagName('tbody')[0];

let todos = [];
let nextTaskNumber = 1;

todoForm.addEventListener('submit', function(event) {
    event.preventDefault();
    addTodo();
});

function addTodo() {
    const taskName = taskNameInput.value.trim();
    const priority = parseInt(priorityInput.value);
    let dueDate = dueDateInput.value ? new Date(dueDateInput.value) : new Date();
    
    if (!taskName || priority < 1 || priority > 5) {
        alert("Täytä kaikki kentät oikein!");
        return;
    }

    if (dueDate < new Date()) {
        dueDate.setDate(new Date().getDate() + 1);
    }

    const todo = {
        nro: nextTaskNumber++,
        taskName,
        priority,
        dueDate: dueDate.toISOString().split('T')[0],
        status: 'Kesken'
    };

    todos.push(todo);
    displayTodos();
    todoForm.reset();
}

function displayTodos() {
    todoTable.innerHTML = '';
    todos.forEach(todo => {
        const row = todoTable.insertRow();
        row.className = todo.status === 'Valmis' ? 'completed' : '';
        
        row.insertCell(0).innerText = todo.nro;
        row.insertCell(1).innerText = todo.taskName;
        row.insertCell(2).innerText = todo.priority;
        row.insertCell(3).innerText = todo.dueDate;
        
        const statusCell = row.insertCell(4);
        statusCell.innerText = todo.status;
        if (todo.status === 'Kesken') {
            statusCell.addEventListener('click', () => markAsComplete(todo.nro));
        }
    });
}

function markAsComplete(nro) {
    const todo = todos.find(t => t.nro === nro);
    if (todo && todo.status === 'Kesken') {
        todo.status = 'Valmis';
        displayTodos();
    }
}
