/**
* Single Round Match 549 Round 1 - Division II, Level One
*/
public class BallAndHats {

	public static void main(String[] args) {
		System.out.println(getHat("o..", 101));
	}

	public static int getHat(String hats, int numSwaps) {

		int pos = hats.indexOf('o');
		if (numSwaps == 0)
			return pos;

		return (pos == 1) ? (numSwaps % 2 == 0) ? 1 : 0 : (numSwaps % 2 == 0) ? 0 : 1;

	}
}