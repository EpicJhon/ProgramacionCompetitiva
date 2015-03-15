/**
*  Member Single Round Match 491 Round 1 - Division II, Level One
*/

public class OneDigitDifference {

	public static int getSmallest(int N) {
		if (N == 0)
			return 1;
		return Integer.parseInt("0".concat(String.valueOf(N).substring(1)));

	}
}