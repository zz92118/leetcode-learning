package class27;

public class Code01_KMP {

	public static int getIndexOf(String s1, String s2) {
		if (s1 == null || s2 == null || s2.length() < 1 || s1.length() < s2.length()) {
			return -1;
		}
		char[] str1 = s1.toCharArray();
		char[] str2 = s2.toCharArray();
		int x = 0;//str1比对的位置
		int y = 0;//str2比对位置
		// O(M) m <= n
		int[] next = getNextArray(str2);
		// O(N)
		while (x < str1.length && y < str2.length) {
			//相等
			if (str1[x] == str2[y]) {
				x++;
				y++;
			} 
			// str2比对的位置无法向前跳了,str1换一个分支
			else if (next[y] == -1) { // y == 0 y到了0位置 next数组的0位置 str2不能再往前跳了
				x++;//str1换一个开头
			} 
			//str2往前跳
			else {
				y = next[y];//往前跳的过程
			}
		}
		//i1-i2是,returni1匹配上的开头
		// i2越界:得到匹配
		// i1越界:无法得到匹配
		return y == str2.length ? x - y : -1;
	}

	public static int[] getNextArray(char[] str2) {
		if (str2.length == 1) {
			return new int[] { -1 };
		}
		int[] next = new int[str2.length];
		next[0] = -1;
		next[1] = 0;
		int i = 2; // 目前在哪个位置上求next数组的值
		int cn = 0; // 当前是哪个位置的值再和i-1位置的字符比较
		while (i < next.length) {
			if (str2[i - 1] == str2[cn]) { // 配成功的时候
				next[i++] = ++cn;
			} else if (cn > 0) {
				cn = next[cn];
			} else {
				next[i++] = 0;
			}
		}
		return next;
	}

	// for test
	public static String getRandomString(int possibilities, int size) {
		char[] ans = new char[(int) (Math.random() * size) + 1];
		for (int i = 0; i < ans.length; i++) {
			ans[i] = (char) ((int) (Math.random() * possibilities) + 'a');
		}
		return String.valueOf(ans);
	}

	public static void main(String[] args) {
		int possibilities = 5;
		int strSize = 20;
		int matchSize = 5;
		int testTimes = 5000000;
		System.out.println("test begin");
		for (int i = 0; i < testTimes; i++) {
			String str = getRandomString(possibilities, strSize);
			String match = getRandomString(possibilities, matchSize);
			if (getIndexOf(str, match) != str.indexOf(match)) {
				System.out.println("Oops!");
			}
		}
		System.out.println("test finish");
	}

}
