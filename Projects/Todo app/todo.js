
var ul = document.getElementById('list');
var li;

var addbutton = document.getElementById('add');
addbutton.addEventListener('click',additem);

var removebutton = document.getElementById('remove');
removebutton.addEventListener('click',removeitem);

var removebutton = document.getElementById('removeall');
removebutton.addEventListener('click',removeallitem);



function additem(){
    var input = document.getElementById('input');
    var item = input.value;
    ul = document.getElementById('list');
    var te = document.createTextNode(item);
    if (item === '') {
       /*const entertodo = document.querySelector('#entertodo');
       entertodo.textContent = 'Please Enter the Todo';
       document.querySelector('#entertodo').appendChild(entertodo);
       entertodo.textContent = '';*/
       

       
        return false;
    }
    else{
        li = document.createElement('li');
        var checkbox = document.createElement('input');
        checkbox.type = 'checkbox';
        checkbox.setAttribute('id','check');
        var label = document.createElement('label');
        ul.appendChild(label);
        li.appendChild(checkbox);
        label.appendChild(te);
        li.appendChild(label);
        ul.insertBefore(li,ul.childNodes[0]);
        
          
        setTimeout(() => {
            li.className='visual';  
        }, 2);

        input.value='';

    }

    
}

function removeitem(){
    li = ul.children;
    for (let i = 0; i < li.length; i++) {
        while(li[i] && li[i].children[0].checked){
            ul.removeChild(li[i]);
        }
        
    }
    
}

function removeallitem(){
    li=ul.children;
    for (let i = 0; i< li.length; i++) {
      const element = li[i];
       ul.remove();
    }
}