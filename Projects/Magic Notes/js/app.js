document.getElementById("msgDiv").style.display  = "none";
showNotes();

// If user adds a note, add it to the local storage
let addBtn = document.getElementById('addBtn');
addBtn.addEventListener('click', function (e) {
    // Get the note title and note text from text fields
    titleText = document.getElementById('titleText');
    noteText = document.getElementById('noteText');
    // Get the already saved notes
    let notes = localStorage.getItem('notes');

    if (notes == null) {
        notesObj = [];
    }
    else {
        notesObj = JSON.parse(notes);
    }

    if (titleText.value != '' && noteText.value != '') {
        let myObj = {
            title: titleText.value,
            text: noteText.value
        }
        notesObj.push(myObj);
        localStorage.setItem('notes', JSON.stringify(notesObj));
        titleText.value = '';
        noteText.value = '';
        // console.log(notesObj);
        document.getElementById("msgDiv").style.display  = "none";
        showNotes();
    }
    else{
        document.getElementById("msgDiv").style.display  = "block";
    }
});

// Function to show elements from local storage
function showNotes() {
    let notes = localStorage.getItem('notes');
    if (notes == null) {
        notesObj = [];
    }
    else {
        notesObj = JSON.parse(notes);
    }

    let html = '';

    notesObj.forEach(function (element, index) {
        html += `
            <div class="noteCard my-2 mx-2 card" style="width: 18rem;">
                <div class="card-body">
                    <h5 class="card-title">${element.title}</h5>
                    <p class="card-text">${element.text}</p>
                    <button id="${index}" onClick="deleteNote(this.id)" class="btn btn-primary" id="deleteBtn">Delete Note</button>
                </div>
            </div>
        `;
    });

    let notesElement = document.getElementById('notes');
    if (notesObj.length != 0) {
        notesElement.innerHTML = html;
    }
    else {
        notesElement.innerHTML = `Nothing to show! Use "Add a Note" section above to add notes.`;
    }
}

// function to delete note from localStorage
function deleteNote(index) {
    let notes = localStorage.getItem('notes');
    if (notes == null) {
        notesObj = [];
    }
    else {
        notesObj = JSON.parse(notes);
    }

    notesObj.splice(index, 1);      // first argument - to start from, second argument - number of elements to delete
    localStorage.setItem('notes', JSON.stringify(notesObj));
    showNotes();
}

let searchText = document.getElementById('searchText');
searchText.addEventListener('input', function(){
    let inputVal = searchText.value.toLowerCase();
    // console.log('Input Event Fired!', inputVal);
    let noteCards = document.getElementsByClassName('noteCard');
    Array.from(noteCards).forEach(function(element){
        let cardText = element.getElementsByTagName('p')[0].innerText;
        // console.log(cardText);
        if(cardText.toLocaleLowerCase().includes(inputVal)){
            element.style.display = 'block';
        }
        else{
            element.style.display = 'none';
        }
    });
});