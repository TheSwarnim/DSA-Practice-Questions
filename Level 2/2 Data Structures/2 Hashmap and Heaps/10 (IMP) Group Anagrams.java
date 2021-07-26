import java.util.*;

public class Main {

	public static ArrayList<ArrayList<String>> groupAnagrams(String[] strs) {
		var lol = new ArrayList<ArrayList<String>>();

		var bm = new HashMap<HashMap<Character, Integer>, ArrayList<String>>();

		for (String str : strs) {
			var m = new HashMap<Character, Integer>();
			for(char c : str.toCharArray()){
				m.put(c, m.getOrDefault(c, 0) + 1);
			}
			
			bm.computeIfAbsent(m, k -> new ArrayList<>()).add(str);
		}

		for(var val : bm.values()){
			lol.add(val);
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
		ArrayList<ArrayList<String>> anagramsGrouped = groupAnagrams(arr);
		for (ArrayList<String> lst : anagramsGrouped) {
			Collections.sort(lst);
		}
		anagramsGrouped.sort(new ListComparator());
		display(anagramsGrouped);

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
