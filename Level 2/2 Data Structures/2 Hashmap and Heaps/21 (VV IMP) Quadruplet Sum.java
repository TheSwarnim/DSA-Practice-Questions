import java.util.*;

public class Main {
    public static List<List<Integer>> fourSum(int[] nums, int target, int n) {
        List<List<Integer>> lol = new ArrayList<>();
        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 3; i++) {
            if(i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int sum = target - nums[i];
                var res = threeSum(nums, i + 1, sum);
                if(res.size() != 0 && res.get(0).size() != 0) {
                    appendInList(lol, res, nums[i]);
                }
            }
        }

        return lol;
    }

    public static void appendInList(List<List<Integer>> main, List<List<Integer>> sec, int val){
        for(var li : sec){
            main.add(Arrays.asList(val, li.get(0), li.get(1), li.get(2)));
        }
    }

    public static List<List<Integer>> threeSum(int[] nums, int x, int target) {
        List<List<Integer>> lol = new ArrayList<>();
        
        for (int i = x; i < nums.length - 2; i++) {
            if(i == x || (i > x && nums[i] != nums[i - 1])) {
                int lo = i + 1, hi = nums.length - 1, sum = target - nums[i];
                while(lo < hi){
                    if(nums[lo] + nums[hi] == sum) {
                        lol.add(Arrays.asList(nums[i], nums[lo], nums[hi]));
                        while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        while(lo < hi && nums[hi] == nums[hi - 1]) hi--;
                        lo++; hi--;
                    } else if(nums[lo] + nums[hi] < sum) lo++;
                    else hi--;
                }
            }
        }

        return lol;
    }

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		int target = sc.nextInt();
		List<List<Integer>> ans = fourSum(arr, target, n);
		Collections.sort(ans,(a,b)->{
            int i = 0;
            int j = 0;
            
            while(i < a.size()){
                if(a.get(i) == b.get(j)){
                    i++;
                    j++;
                }else{
                    return a.get(i) - b.get(j);
                }
            }
            
            return 0;
        }); 
		for (List<Integer> a : ans) {
			for (int element : a) {
				System.out.print(element + " ");
			}
			System.out.println();
		}

        sc.close();
	}

}
