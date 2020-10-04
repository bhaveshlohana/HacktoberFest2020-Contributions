//Just want to share the power of JS how 4 lines can be written in 1 single conditional statement, peace!<3

var culprits = [11172,434];
for(var i = 0 ; i < culprits.length ; i++){
  if(culprits[i].toString()==culprits[i].toString().split("").reverse().join("")){
    console.log("culprit",i," is a Palindrome");
  }else{
    console.log("culprit",i," is not a Palindrome");
  }
}
