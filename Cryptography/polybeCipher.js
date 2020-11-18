/*Encrypt and decrypt using polybe square cipher */

var alphabet= 'ABCDEFGHIJKLMNOPQRSTUVXYZ';

function creerGrille (clef)
{
	let grille  = '';
	for(let nbr = 0; nbr < Math.min(clef.length,25); nbr++){
		ch= clef.charAt(nbr)
		if (grille.indexOf (ch) < 0) {
			grille += ch
		}
	}
	for(let nbr = 0; nbr < alphabet.length; nbr++){
		ch= alphabet.charAt(nbr)
		if (grille.indexOf (ch) < 0) {
			grille += ch
		}
	}
	return grille
}

function polybe(entree,cle,op)
{
	var cle=creerGrille(cle);
	var carre=[[],[],[],[],[]];
	let i=0;
	for(let c=0; c<5; c++){
		carre[c]=cle.substring(i,i+5).split(''); i+=5;
	}
     var substi=new Array(25);	
	 var alphabet_polybe='12345';
    for (i=0;i<25;i++) 
       substi[i]="";

	//var entree=formate_entree_polybe(entree.value);
	// On commence par faire le carré de Polybe;..
	for (i=0;i<5;i++)
	  for (var j=0;j<5;j++)
	  {
	    substi[alphabet.indexOf(carre[i][j])]=alphabet_polybe.charAt(i)+alphabet_polybe.charAt(j);
	  }
	var sortie="";
	
	  if(op===0){
		for (i=0;i<entree.length;i++)
			sortie+=substi[alphabet.indexOf(entree.charAt(i))];
		// completer "sortie" pour quel soit multiple de 5
		let l = 5-sortie.length%5;
		if(l!==5){
			i=0;
			for(i=0;i<l;i++){
				sortie+=Math.floor(Math.random()*5)+1; // add random int from 1 to 5
			}
		}
  }
	  else if(op===1){
		  
		let l = entree.length%2===0 ? entree.length/2 : (entree.length-1)/2; 
		for (i=0;i<l;i++)
			 sortie+=carre[parseInt(entree.charAt(2*i)-1,10)][parseInt(entree.charAt(2*i+1)-1,10)];
	  }
	return sortie+cle;
}
//console.log(polybe("CACHELORDANSLASOUCHEDELARBRE","EXEMPLEPLAYFAIR",0)) ;
//console.log(polybe("322132351115442533214351152151445332351133111521253125113432","EXEMPLEPLAYFAIR",1));
