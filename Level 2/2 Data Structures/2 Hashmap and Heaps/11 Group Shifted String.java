import java.util.*;

public class Main {

	public static ArrayList<ArrayList<String>> groupShiftedStrings(String[] strs) {
		var lol = new ArrayList<ArrayList<String>>();

		var map = new HashMap<String, ArrayList<String>>();
		for(String str : strs){
			StringBuilder sb = new StringBuilder();
			for(int i = 1; i < str.length(); i++){
				int diff = str.charAt(i) - str.charAt(i - 1);
				if(diff < 0){
					diff += 26;
				}
				sb.append(Integer.toString(diff) + "#");
			}
			map.computeIfAbsent(sb.toString(), k -> new ArrayList<>()).add(str);
		}

		for(var m : map.values()){
			lol.add(m);
		}

		return lol;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String[] arr = new String[N];
		for (int i = 0; i < N; i++) {
			arr[i] = sc.next();
		}
		ArrayList<ArrayList<String>> shiftedGroup = groupShiftedStrings(arr);
		for (ArrayList<String> lst : shiftedGroup) {
			Collections.sort(lst);
		}
		shiftedGroup.sort(new ListComparator());
		display(shiftedGroup);

		sc.close();
	}

	// it is used to make the result unique
	static class ListComparator implements Comparator<List<String>> {
		@Override
		public int compare(List<String> l1, List<String> l2) {
			if (l1.size() != l2.size()) {
				return l2.size() - l1.size();
			}

			String l1str = l1.get(0);
			String l2str = l2.get(0);
			return l1str.compareTo(l2str);

		}
	}

	public static void display(ArrayList<ArrayList<String>> list) {
		for (int i = 0; i < list.size(); i++) {
			ArrayList<String> currList = list.get(i);
			for (int j = 0; j < currList.size(); j++) {
				System.out.print(currList.get(j) + " ");
			}
			System.out.println();
		}
	}

}
