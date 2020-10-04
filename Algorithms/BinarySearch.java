class BinarySearch {

    int binarySearch(int arr[], int value)
    {
        int l = 0, r = arr.length - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;

            // Check if the value exists in the middle
            if (arr[m] == value)
                return m;

            // If value is greater than mid value
            // ignore the left chunk of the array
            if (arr[m] < value)
                l = m + 1;

            // If value is less than mid value
            // ignore the right chunk of the array
            else
                r = m - 1;
        }

        // the value must not exist in data set
        return -1;
    }
    public static void main(String args[])
    {
        BinarySearch tree = new BinarySearch();

        int arr[] = { 1, 3, 17, 28, 29, 90, 91, 92, 93, 120, 189, 200, 289};
        int value = 10;
        int returnVal = tree.binarySearch(arr, value);
        if (returnVal == -1)
            System.out.println("Value does no exist");
        else
            System.out.println("Value exists at index " + returnVal);
    }
}
