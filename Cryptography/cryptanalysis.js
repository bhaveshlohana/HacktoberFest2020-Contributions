/* functions that decrypt substition ciphers (vigenere, beaufort and Germand) by statistic cryptalysis and coincidence index*/ 
function sortbyOccurences(a,b)
{
    return parseInt(b.Occurences) - parseInt(a.Occurences);
}
ecartList = (objTrig) =>{
  objTrig["Ecart"]=[];
    for(let i = 0; i< objTrig["Position"].length - 1;i++)
    {
        for(let j = i+1; j<objTrig["Position"].length;j++)
            objTrig["Ecart"].push(Math.abs(objTrig["Position"][j] - objTrig["Position"][i]))  ;

    }
}
// Calcul le pgcd de tous les ecart puis retournent un array tableau des diviseurs comms au Ecarts
pgcdList = (listEcart, keyMin,keyMax) =>{
  let pgcdEcart=[];
  // Si n'y a qu un seul ecart on cherche ses diviseurs entre keyMin et KeyMax
  if(listEcart.length === 1){
    let c=keyMin, l =Math.ceil(listEcart[0]/2);
    while(c < l && c  <= keyMax){
        if(listEcart[0] % c ===0) 
             pgcdEcart.push(c) ;
      c++;
    }
    if(listEcart[0]<=keyMax)
      pgcdEcart.push(listEcart[0]);
   return pgcdEcart; 
  }
  // sinon
    for(let i = 0; i<listEcart.length - 1;i++)   {  
        for(let j = i+1; j<listEcart.length;j++)
        {
           let currPgcd =  pgcd(listEcart[j], listEcart[i])
           if( currPgcd >= keyMin  && currPgcd <= keyMax )
             pgcdEcart.push(currPgcd);
        }
            
    }
    if(pgcdEcart.length === 0)
    return [];
    // retourne un objet qui a pour cle les pgcd et pour valeur leurs nombres doccurences
    let pgcdObjt = pgcdEcart.reduce( (acc, curr) =>{
      acc[curr] ? acc[curr]++ : acc[curr] = 1;
      return acc; 
    },{});
    // on recupere les cle selon leurs ordres doccurence
  let listCle = Object.keys(pgcdObjt).sort( (a,b)=>{ return  pgcdObjt[b] - pgcdObjt[a]})//.map(Number);
  //Ajoutons les diviseurs du plus petit des PGCDs de tous les  ecarts, diviseurs superieurs a  keyMin  
  let minCle = Math.min(...listCle);
  let diviseurMin=[], c=keyMin, l=Math.ceil(minCle/2);
  while(c <= l ){
      if(minCle % c ===0) 
           diviseurMin.push(c) ;
    c++;
  }
  listCle.splice(listCle.indexOf(minCle),0,...diviseurMin);
  return listCle;
   
}

function trigramme(texte, keymin=3, keyMax=25)
{
	var trigrammes=new Array(17576);
	var alphabet='ABCDEFGHIJKLMNOPQRSTUVWXYZ';
	
	var i;
	var j;
	var k;
   // On commence par initialiser le tableau des bigrammes...
   for (i=0;i<26;i++)
     for (j=0;j<26;j++)
       for (k=0;k<26;k++)
       {
       	  trigrammes[i*26*26+j*26+k]=new Object;
       	  trigrammes[i*26*26+j*26+k]["Trigrammes"]=alphabet.charAt(i)+alphabet.charAt(j)+alphabet.charAt(k);;
          trigrammes[i*26*26+j*26+k]["Occurences"]=0;
          trigrammes[i*26*26+j*26+k]["Position"]=[];
       }
       
  //On le remplit!
  
  for (i=0;i<texte.length-2;i++)
  {
    trigrammes[alphabet.indexOf(texte.charAt(i))*26*26+alphabet.indexOf(texte.charAt(i+1))*26+alphabet.indexOf(texte.charAt(i+2))]["Occurences"]++;
    trigrammes[alphabet.indexOf(texte.charAt(i))*26*26+alphabet.indexOf(texte.charAt(i+1))*26+alphabet.indexOf(texte.charAt(i+2))]["Position"].push(i+1);
  
  }     
       
  //On trie le tableau
  trigrammes.sort(sortbyOccurences);
  // Onrecupere que les trigrammes aparu pls dune fois   
    i=0;
  while(trigrammes[i]["Occurences"]>1) {
      ecartList(trigrammes[i]);
      i++;  
  }     
  if(i === 0){
      return [{"Repetition":"NEANT"}];
  }
  trigrammes = trigrammes.slice(0,i) ;       
  let allEcart = trigrammes.reduce((accumulator, obj) => accumulator.concat(obj["Ecart"]),[] );
  let listPgcd = pgcdList(allEcart,keymin,keyMax);
  trigrammes.push({"LougueurCle" : listPgcd}) ;
/*   console.log("Tous les ecarts"+allEcart + " -- total " + allEcart.length);
  console.log(" --------------------- ------------------------  ");
  console.log(" Longueur Cle Probable " + listPgcd)  */
 	return trigrammes;	
}
function bigramme(texte,keymin=3, keyMax=25)
{
	var bigrammes=new Array(676);
	var alphabet='ABCDEFGHIJKLMNOPQRSTUVWXYZ';
	
	var i;
	var j;
    var sortie='';
    sortie+="Nombre de caracteres analyses du texte : "+texte.length+"\n";
// On commence par initialiser le tableau des bigrammes...
   for (i=0;i<26;i++)
     for (j=0;j<26;j++)
       {
       	  bigrammes[i*26+j]=new Object;
       	  bigrammes[i*26+j]["Bigrammes"]=alphabet.charAt(i)+alphabet.charAt(j);
           bigrammes[i*26+j]["Occurences"]=0;
           bigrammes[i*26+j]["Position"]=[];
           
       }    
  //On le remplit!
  for (i=0;i<texte.length-1;i++)
  {
    bigrammes[alphabet.indexOf(texte.charAt(i))*26+alphabet.indexOf(texte.charAt(i+1))]["Occurences"]++;
    bigrammes[alphabet.indexOf(texte.charAt(i))*26+alphabet.indexOf(texte.charAt(i+1))]["Position"].push(i+1);
  }     
       
  //On trie le tableau
  bigrammes.sort(sortbyOccurences);
  i=0;
  while(bigrammes[i]["Occurences"]>1) {
    ecartList(bigrammes[i]);
    i++;  
}     
if(i === 0){
    return [{"Repetition":"NEANT"}];
}
  bigrammes = bigrammes.slice(0,i);
  let allEcart = bigrammes.reduce((accumulator, obj) => accumulator.concat(obj["Ecart"]),[] );
  let listPgcd = pgcdList(allEcart,keymin,keyMax);
  bigrammes.push({"LougueurCle" : listPgcd}) ;
 return bigrammes; 
}
function quadrigramme(texte, keyMin=3, keyMax=25)
{
	var quadrigrammes=new Array(456976);
	var alphabet='ABCDEFGHIJKLMNOPQRSTUVWXYZ';
	var i;
	var j;
	var k;
	var l;
   // On commence par initialiser le tableau des bigrammes...
   for (i=0;i<26;i++)
     for (j=0;j<26;j++)
       for (k=0;k<26;k++)
         for (l=0;l<26;l++)
         {
       	    quadrigrammes[i*26*26*26+j*26*26+k*26+l]=new Object;
       	    quadrigrammes[i*26*26*26+j*26*26+k*26+l]["Quadrigrammes"]=alphabet.charAt(i)+alphabet.charAt(j)+alphabet.charAt(k)+alphabet.charAt(l);
             quadrigrammes[i*26*26*26+j*26*26+k*26+l]["Occurences"]=0;
             quadrigrammes[i*26*26*26+j*26*26+k*26+l]["Position"]=[];
         }
       
  //On le remplit!
  
  for (i=0;i<texte.length-3;i++)
  {
  	quadrigrammes[alphabet.indexOf(texte.charAt(i))*26*26*26+alphabet.indexOf(texte.charAt(i+1))*26*26+alphabet.indexOf(texte.charAt(i+2))*26+alphabet.indexOf(texte.charAt(i+3))]["Occurences"]++;
    quadrigrammes[alphabet.indexOf(texte.charAt(i))*26*26*26+alphabet.indexOf(texte.charAt(i+1))*26*26+alphabet.indexOf(texte.charAt(i+2))*26+alphabet.indexOf(texte.charAt(i+3))]["Position"].push(i+1);
  }     
       
  //On trie le tableau
  quadrigrammes.sort(sortbyOccurences);
  i=0;
  while(quadrigrammes[i]["Occurences"]>1) {
      ecartList(quadrigrammes[i]);
      i++;  
  }     
  if(i === 0){
      return [{"Repetition":"NEANT"}];
  }
  quadrigrammes = quadrigrammes.slice(0,i) ;       
  let allEcart = quadrigrammes.reduce((accumulator, obj) => accumulator.concat(obj["Ecart"]),[] );
  let listPgcd = pgcdList(allEcart,keyMin,keyMax);
  quadrigrammes.push({"LougueurCle" : listPgcd}) ;

  return quadrigrammes;     
}


function pgcd(a,b) {
  a = Math.abs(a);
  b = Math.abs(b);
  if (b > a) {var temp = a; a = b; b = temp;}
  while (b) {
      temp = b;
      b = a % b;
      a = temp;
  }
  return a;
}
// Ensemble de fonctions qui tentent de decrypter automatiquement
// Un message chiffre avec le chiffre de Vigenère ou ses variantes
// Senecrypt 
var alphabet='ABCDEFGHIJKLMNOPQRSTUVWXYZ';
var MINCLE=1;
var MAXCLE=25;
var frequencetheo=[0.0797,0.0107,0.0347,0.0400,0.1800,0.01010,0.0104,0.0135,0.0734,0.0030,0.0007,0.0548,0.0317,0.0702,0.0527,0.0280,0.0113,0.0664,0.0772,.0728,.0574,.0117,.0006,.0045,.0031,.0004];

function analyseGenreVigenere(entree,algo) {

  let sortie={};
	let maxindice=0;
  let longueurcle=1;
	let indice;
	let dec,i;
	let nombres,cle;
	
	var ligneencours,colencours,result="";
	
	for (i=MINCLE;i<=Math.min(MAXCLE,entree.length-1);i++)
	{
		indice=0;
		for (dec=0;dec<i;dec++)
		{
			prov=extrait(entree,i,dec);
			indice=indice+indiccoinc(prov);			
		}
		indice=indice/i;
		if (indice>maxindice) 
		{
			maxindice=indice;
			longueurcle=i;
		}
		/* Si l'indice est anormalement grand, on s'éjecte !*/
		if (indice>0.075) i=MAXCLE;
	}

	sortie["indice"]=Number(indice.toFixed(4));
	sortie["longCle"]=longueurcle; 
	cle="";
	for (i=0;i<longueurcle;i++)
	{
		// On calcule les frÃ©quences des lettres chiffrÃ©es avec cette lettre de la cle.

		prov=extrait(entree,longueurcle,i);
    nombres=calculfrequences(prov);
    if(algo==="Vigenere")
      cle=cle+alphabet.charAt(optimise(nombres));
    else if(algo === "Allemande")
      cle=cle+alphabet.charAt(26-optimise(nombres));
    else if (algo==="Beaufort")
    cle=cle+alphabet.charAt((26-optimise(nombres))%26);
 }
	
	sortie["cle"]=cle;
	
	if(algo === "Vigenere"){
      for (i=0; i<entree.length; i++)
    {
      ligneencours=alphabet.indexOf(entree.charAt(i));
      colencours=alphabet.indexOf(cle.charAt(i%cle.length));
      ajout=alphabet[ ((ligneencours-colencours)+26)%26]; // changer pour adapter a beaufort , allmande ...
      result=result+ajout;
    }
  }
  else if(algo==="Beaufort"){
    for (i=0; i<entree.length; i++)
	{
		ligneencours=alphabet.indexOf(entree.charAt(i));
		colencours=alphabet.indexOf(cle.charAt(i%cle.length));
		ajout=alphabet[ ((colencours-ligneencours)+26)%26]; // changer pour adapter a beaufort , allmande ...
		result=result+ajout;
	}
}
  else if(algo==="Allemande") {
    for (i=0; i<entree.length; i++)
	{
		ligneencours=alphabet.indexOf(entree.charAt(i));
		colencours=alphabet.indexOf(cle.charAt(i%cle.length));
		ajout=alphabet[ (ligneencours+colencours)%26]; // changer pour adapter a beaufort , allmande ...
		result=result+ajout;
	}
  }
	sortie["clair"] = result;	
	return sortie;
}

// La fonction suivante extraite d'une chaine une sous-chaine en prenant tous les "ecarts" caractÃ¨res
// et en commenÃ§ant Ã  "depart"

function extrait(chaine,ecart,depart)
{
	var resultat="";
	var i=+depart;
	
	while (i<chaine.length)
	{
		resultat+=chaine.charAt(i);
		i+=ecart;
	}
	
	return resultat;
}


// Les fonctions suivantes sont consacrees au calcul de l'indice de coincidence du texte

function indiccoinc(texte)
{
	var nombres=new Array(26);  // Le nombre de fois que chaque lettre intervient dans le texte
	var indice=0.0;
	var nb=0;
	
	// On commence par réaliser les pourcentages...
	nombres=calculnombres(texte);
	for (var i=0;i<26;i++)
	{
		indice=nombres[i]*(nombres[i]-1)+indice;
		nb=nb+nombres[i];
	}
	indice=indice/(nb*(nb-1));
	return indice;
}

    
function calculnombres(texte)
{
	var nombres=new Array(26);
	var nb,prov,j;
	
	for (var i=0;i<26;i++)
	{
		nombres[i]=0.0;
	}
	for (var i=0;i<texte.length;i++)
	{
		nombres[alphabet.indexOf(texte.charAt(i))]++;
	}	
	
	return nombres;
}

function indice_coincidences(texte,clemin,clemax)
{
	var i,indice;
	var sortie="";
	
	
	for (i=Math.max(clemin,2);i<=Math.min(clemax,entree.length-1);i++)
	{
		indice=0;
		for (dec=0;dec<i;dec++)
		{
			prov=extrait(entree,i,dec);
			indice=indice+indiccoinc(prov);			
		}
		indice=Math.round(indice*1000/i)/1000;
		sortie=sortie+"Pour une longueur de clÃ© de "+i+", l'indice de coÃ¯ncidence vaut "+indice+"\n";
	}
	
	return sortie;
	
}

// Les fonctions suivantes permettent de choisir la clé (une fois sa longueur connue)
// en optimisant l'écart par rapport Ã  la frÃ©quence thÃ©orique

function calculfrequences(texte)
{
	var nombres=calculnombres(texte);
	var i;
	
	for (i=0;i<26;i++) 
	{
		nombres[i]=nombres[i]/texte.length;
	}	
	
	return nombres;
}

function optimise(nombres)
{
   var meilleur=0;
   var mincomp=10;
   var prov;
   var i,j;
   
   for (i=0;i<26;i++)
   {
		prov=0;
		for (j=0;j<26;j++)
		{
		    prov=prov+(nombres[(j+i+26)%26]-frequencetheo[j])*(nombres[(j+i+26)%26]-frequencetheo[j]);
		}
		if (prov<mincomp)
		{
		    mincomp=prov;
		    meilleur=i;
		}
	}
	return meilleur;
}

//console.log(analyseGenreVigenere("JCCMFQKDWLFVZQWCSCESXYOAVSXLWARBBVZQEQWEGKZSVKZQXCBVDIIZWIUCVWTJSTZUWKOQKXIDOQJSTCSVRJIZHBRBBISDVRMJJQJOOVGLVBWPSARTNCSCIOQVBBRZIJIZWOKVRCESUVFMKOTVSTCSDFMIZHTVGGVIFMSZKGAFIDIWZVHAVFMWSZDSZTCUDSTVGDRZDVGTVBBVGLLBKFECZZTRUMVBBISLVIFVOCOZMJCUDSQCSUGCZKOQKQMJTITSAUSOZGIEHACSAZZMEQMCOXRWFCSDZRMGFMJECVXIMOQJJCLBNLFMKCCLBMWCCZBMKFIMSZJSZCSURQIUOUCSZLPIEECZRMWWTVSBKCCJQMJFCSOVJGCIZIICCKSMKQMLLYLCVECCJOKTFWTVMJIZCOXFWBIWVVIVACCICCCOCKFMJINWWBUOBKSVUFM"));
/* console.log(trigramme("KQOWEFVJPUJUUNUKGLMEKJINMWUXFQMKJBGWRLFNFGHUDWUUMB"+
"SVLPSNCMUEKQCTESWREEKOYSSIWCTUAXYOTAPXPLWPNTCGOJBGFQHTDWXIZAYGFFNSXCSEYNCTSSPNTUJNYTGGWZGR"+
"WUUNEJUUQEAPYMEKQHUIDUXFPGUYTSMTFFSHNUOCZGMRUWEYTRGKMEEDCTVRECFBDJQC"+
"USWVBPNLGOYLSKMTEFVJJTWWMFMWPNMEMTMHRSPXFSSKFFSTNUOCZGMDOEOYEEKCPJRGP"+
"MURSKHFRSEIUEVGOYCWXIZAYGOSAANYDOEOYJLWUNHAMEBFELXYVLWNOJNSIOFRWUCCESWKVIDGMUCGOCRUWGNMAAFFVNSIUDEKQHCEUCPFC"+
"MPVSUDGAVEMNYMAMVLFMAOYFNTQCUAFVFJNXKLNEIWCWODCCULWRIFT"+
"WGMUSWOVMATNYBUHTCOCWFYTNMGYTQMKBBNLGFBTWOJFTWGNTEJKNEE"+
"DCLDHWTYYIDGMVRDGMPLSWGJLAGOEEKJOFEKUYTAANYTDWIYBNLNYNP"+
"WEBFNLFYNAJEBFR")); */ // cle =5 
//console.log(trigramme("LFWKIMJCLPSISWKHJOGLKMVGURAGKMKMXMAMJCVXWUYLGGIISWALXAEYCXMFKMKBQBDCLAEFLFWKIMJCGUZUGSKECZGBWYMOACFVMQKYFWXTWMLAIDOYQBWFGKSDIULQGVSYHJAVEFWBLAEFLFWKIMJCFHSNNGGNWPWDAVMQFAAXWFZCXBVELKWMLAVGKYEDEMJXHUXDAVYXL",3,16)); // cle = 6
//console.log(quadrigramme("JCCMFQKDWLFVZQWCSCESXYOAVSXLWARBBVZQEQWEGKZSVKZQXCBVDIIZWIUCVWTJSTZUWKOQKXIDOQJSTCSVRJIZHBRBBISDVRMJJQJOOVGLVBWPSARTNCSCIOQVBBRZIJIZWOKVRCESUVFMKOTVSTCSDFMIZHTVGGVIFMSZKGAFIDIWZVHAVFMWSZDSZTCUDSTVGDRZDVGTVBBVGLLBKFECZZTRUMVBBISLVIFVOCOZMJCUDSQCSUGCZKOQKQMJTITSAUSOZGIEHACSAZZMEQMCOXRWFCSDZRMGFMJECVXIMOQJJCLBNLFMKCCLBMWCCZBMKFIMSZJSZCSURQIUOUCSZLPIEECZRMWWTVSBKCCJQMJFCSOVJGCIZIICCKSMKQMLLYLCVECCJOKTFWTVMJIZCOXFWBIWVVIVACCICCCOCKFMJINWWBUOBKSVUFM",3,20)); // cle = 3
//console.log(bigramme("MFUVAHGUTSGVMFUTUJPPETQSOUCIFP",4,10)) // 3
module.exports = {
    trigramme,
    bigramme,
    quadrigramme,
    analyseGenreVigenere
};