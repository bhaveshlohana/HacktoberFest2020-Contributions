// Implementing Binary Search algorithm in C++

int binarySearch(vector<int>& A,int target){
         if(A.size()==0){
             return -1;
         }
        int left = 0;
        int right = A.size()-1;
        while(left<=right){            //To prevent overlapping of left and right values
             int mid = left + (right-left)/2;
             if(A[mid]==target) {return mid;}
             else if(A[mid]<target) {left = mid+1 ; }
             else {right = mid-1;}
        }
        //End condition left>right
        return -1;
}


