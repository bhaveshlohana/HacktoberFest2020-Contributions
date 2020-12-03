//There are two sorted arrays
//nums1 and nums2 of size m and n respectively.
//Find the median of the two sorted arrays. 
//The overall run time complexity should be O(log (m+n)).
//You may assume nums1 and nums2 cannot be both empty.

public class median_of_two_sorted_Arrays {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] nums1 = { 1, 3 };
		int[] nums2 = { 2 };

		double med = median(nums1, nums2);
		System.out.println(med);
	}

	private static double median(int[] nums1, int[] nums2) {

		double med = 0;

		int size = nums1.length + nums2.length;
		int[] ans = new int[size];
		int i = 0;
		int j = 0;

		int k = 0;

		while (i < nums1.length && j < nums2.length) {

			if (nums1[i] < nums2[j]) {
				ans[k] = nums1[i];
				k++;
				i++;
			} else if (nums1[i] == nums2[j]) {
				ans[k] = nums1[i];
				k++;
				i++;
				ans[k] = nums2[j];
				k++;
				j++;
			} else {
				ans[k] = nums2[j];
				k++;
				j++;
			}
		}

		System.out.println(size);

		int idx = size / 2;

		if (size % 2 == 0) {
			System.out.println("hi");
			med = (ans[idx] + ans[idx + 1]) / 2;
		} else {
			System.out.println("bye");
			System.out.println(med = (ans[idx]) / 2);
		}

		for (int l : ans) {
			System.out.print(l + " ");
		}

		return med;
	}

}
