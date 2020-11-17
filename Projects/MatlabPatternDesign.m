# A matrix 6,6 with a pattern of 


# 1 0 1 0 0 0
# 0 2 0 1 0 0 
# 2 0 3 0 1 0 
# 0 2 0 4 0 1 
# 0 0 2 0 5 0 
# 0 0 0 2 0 6 




arr = zeros(6,6);
for i=1:6,
  for j=1:6,
    if(i==j),
      arr(i,i) = i;
    elseif(j-i == 2),
      arr(i,j) = 1;
    elseif(j-i == -2),
      arr(i,j) = 2;
    endif
  endfor
endfor
arr
