const list_items = document.querySelectorAll('.list-item');
const lists = document.querySelectorAll('.list');
var arr = [];
let draggedItem = null;
let chimken=0;
let eggo=0;
let cheeso=0;
let tomato=0;
let lemon=0;
let brocco=0;

let calChimken = 239, calEggo = 155, calBrocco = 35, calCheeso = 402, calTomato = 18, calLemon = 29;



for (let i = 0; i < list_items.length; i++) {
	const item = list_items[i];

	item.addEventListener('dragstart', function () {
        draggedItem = item;
        // console.log(item.innerText);
		// setTimeout(function () {
		// 	item.style.display = 'none';
		// }, 0)
	});

	item.addEventListener('dragend', function () {
		setTimeout(function () {
			draggedItem.style.display = 'block';
			draggedItem = null;
		}, 0);
    })
    
  

	// for (let j = 0; j < lists.length; j ++) {
		const list = lists[0];

		list.addEventListener('dragover', function (e) {
			e.preventDefault();
		});
		
		list.addEventListener('dragenter', function (e) {
			e.preventDefault();
			// this.style.backgroundColor = 'rgba(0, 0, 0,)';
		});

		list.addEventListener('dragleave', function (e) {
			// this.style.backgroundColor = 'rgba(0, 0, 0,)';
		});

		list.addEventListener('drop', function (e) {
            // console.log('drop');
            // console.log(draggedItem.innerText);
            this.append(draggedItem);
            arr.push(draggedItem.innerText);
            console.log(arr);
            //chicken start here
            for(let k in arr) {
                console.log(arr[k]);
                if (arr[k]=="chicken")
                    {
                        chimken++;
                    }
    
            }

            if(chimken!=0){
                    fetch(`https://www.themealdb.com/api/json/v1/1/filter.php?i=chicken`)
                    .then((resgrr) => resgrr.json())
                    .then(data1 => {
                        let output = ``;
                        for(let j =0; j<4; j++)
                        {
                            output+=` <div class="col-md-3 mr-3 mt-4 text-center rounded" style = "background-color : #dee8ff;">
                            <h1 class="text-black p-3" >CHICKEN</h1>
                            <p class="text-black pb-5">${data1.meals[j].strMeal}</p>
              
                        </div>
                          `
                        }
                       let output1 = `<div class=" button1" style="font-size: 50%; font-family: 'Lilita One', cursive;">Chicken : ${calChimken} kcal</div>`;
                       
                       
                       document.getElementById('chicken').innerHTML = output1;
                       

        document.getElementById('data').innerHTML = output;
 
                    })
                }

// Chicken ends here

// Egg starts here

for(let k in arr) {
    console.log(arr[k]);
    if (arr[k]=="egg")
        {
            eggo++;
        }

}

if(eggo!=0){
        fetch(`https://www.themealdb.com/api/json/v1/1/filter.php?i=egg`)
        .then((resgrr1) => resgrr1.json())
        .then(data2 => {
            let output = ``;
            console.log("GRRRRRRRRR");
            for(let j = 0; j< 4; j++)
            {
                output+=`<div class="col-md-3 mr-3 mt-4 text-center rounded" style = "background-color : #dee8ff;">
                <h1 class="text-black p-3" >EGG</h1>
                <p class="text-black pb-5">${data2.meals[j].strMeal}</p>
  
            </div>
              `
            }
            let output1 = `<div class="button1" style="font-size: 50%; font-family: 'Lilita One', cursive;">Egg : ${calEggo} kcal</div>`;
                       document.getElementById('egg').innerHTML = output1;
document.getElementById('data1').innerHTML = output;
        })
    }

//Egg ends here


//Brocco starts here

// for(let k in arr) {
//     console.log(arr[k]);
//     if (arr[k]=="broc")
//         {
//             brocco++;
//         }

// }

// if(brocco!=0){
//         fetch(`https://www.themealdb.com/api/json/v1/1/filter.php?i=broccoli`)
//         .then((resgrr2) => resgrr2.json())
//         .then(data2 => {
//             let output = ``;
//             console.log("GRRRRRRRRR");
//             for(let j = 0; j< 4; j++)
//             {
//                 output+=`<div class="col-md-3 mr-3 bg-dark mt-4 text-center ">
//                 <h1 class="text-white p-3" >BROCCOLI</h1>
//                 <p class="text-white pb-5">${data2.meals[j].strMeal}</p>
//                 <img src="arrowicon-01.png" class="text-right" width="30%", height="30%"  alt="">
  
//             </div>
//               `
//             }
// document.getElementById('data1').innerHTML = output;
//         })
//     }

for(let k in arr) {
    console.log(arr[k]);
    if (arr[k]=="broccoli")
        {
            brocco++;
        }

}

if(brocco!=0){
        fetch(`https://www.themealdb.com/api/json/v1/1/filter.php?i=broccoli`)
        .then((resgrr2) => resgrr2.json())
        .then(data3 => {
            let output = ``;
            for(let j in data3.meals)
            {
                output+=`<div class="col-md-3 mr-3 mt-4 text-center rounded" style = "background-color : #dee8ff;">
                <h1 class="text-black p-3" >BROCCOLI</h1>
                <p class="text-black pb-5">${data3.meals[j].strMeal}</p>
  
            </div>
              `
            }
            let output1 = `<div class="button1" style="font-size: 50%; font-family: 'Lilita One', cursive;">Broccoli : ${calBrocco} kcal</div>`;
                       document.getElementById('broccoli').innerHTML = output1;
document.getElementById('data2').innerHTML = output;
        })
    }

//Brocco ends here

//Tomato starts here

for(let k in arr) {
    console.log(arr[k]);
    if (arr[k]=="tomato")
        {
            tomato++;
        }

}

if(tomato!=0){
        fetch(`https://www.themealdb.com/api/json/v1/1/filter.php?i=tomato`)
        .then((resgrr2) => resgrr2.json())
        .then(data3 => {
            let output = ``;
            for(let j =0; j<4; j++)
            {
                output+=`<div class="col-md-3 mr-3 mt-4 text-center rounded" style = "background-color : #dee8ff;">
                <h1 class="text-black p-3" >TOMATO</h1>
                <p class="text-black pb-5">${data3.meals[j].strMeal}</p>
  
            </div>
              `
            }
            let output1 = `<div class="button1" style="font-size: 50%; font-family: 'Lilita One', cursive;">Tomato : ${calTomato} kcal</div>`;
            document.getElementById('tomat').innerHTML = output1;
document.getElementById('data3').innerHTML = output;
        })
    }


//Tomato ends here

//Lemon starts here

for(let k in arr) {
    console.log(arr[k]);
    if (arr[k]=="lemon")
        {
            lemon++;
        }

}

if(lemon!=0){
        fetch(`https://www.themealdb.com/api/json/v1/1/filter.php?i=lemon`)
        .then((resgrr2) => resgrr2.json())
        .then(data3 => {
            let output = ``;
            for(let j =0; j<4; j++)
            {
                output+=`<div class="col-md-3 mr-3 mt-4 text-center rounded" style = "background-color : #dee8ff;">
                <h1 class="text-black p-3" >LEMON</h1>
                <p class="text-black pb-5">${data3.meals[j].strMeal}</p>  
            </div>
              `
            }
            
            
            let output1 = `<div class="button1" style="font-size: 50%; font-family: 'Lilita One', cursive;">Lemon : ${calLemon} kcal</div>`;
            document.getElementById('lemo').innerHTML = output1;
document.getElementById('data4').innerHTML = output;
        })
    }


//Lemon ends here

//cheeso starts here

for(let k in arr) {
    console.log(arr[k]);
    if (arr[k]=="cheese")
        {
            cheeso++;
        }

}

if(cheeso!=0){
        fetch(`https://www.themealdb.com/api/json/v1/1/filter.php?i=cheese`)
        .then((resgrr2) => resgrr2.json())
        .then(data3 => {
            let output = ``;
            for(let j in data3.meals)
            {
                output+=`<div class="col-md-3 mr-3 mt-4 text-center rounded" style = "background-color : #dee8ff;">
                <h1 class="text-black p-3" >CHEESE</h1>
                <p class="text-black pb-5">${data3.meals[j].strMeal}</p>
  
            </div>
              `
            }
            let output1 = `<div class="button1" style="font-size: 50%; font-family: 'Lilita One', cursive;">Cheese : ${calCheeso} kcal</div>`;
            document.getElementById('cheese').innerHTML = output1;
document.getElementById('data5').innerHTML = output;
        })
    }

    

//cheeso ends here





            // console.log(arr);
			this.style.backgroundColor = 'rgba(0, 0, 0, 0.1)';
        });

    }


// }

        
        

        


