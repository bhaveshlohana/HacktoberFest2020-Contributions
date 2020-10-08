function goMad() {
    var adj = document.getElementById("adj").value;
    var noun = document.getElementById("noun").value;
    var animal = document.getElementById("animal").value;
    var noise = document.getElementById("noise").value;

    document.getElementById("result").innerHTML = adj+ " Macdonald had a " +animal+ 
    ", E-I-E-I-O <br> and on that" +noun+ 
    " he had an Lion, E-I-E-I-O <br> with a "+noise+
    " here <br> and a "+noise+ 
    " there, <br> here a "+noise+ ", there a "+noise+ 
    ", <br> everywhere a "+noise+ ", <br> "+adj+
    " Macdonald had a " +noun+ ", E-I-E-I-O.";
    
    document.getElementById("input").style.display = "none";
}