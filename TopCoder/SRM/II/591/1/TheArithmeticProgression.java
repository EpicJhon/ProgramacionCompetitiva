/**
* TheArithmeticProgression	591	II	1
*/

public class TheArithmeticProgression {
	public static double minimumChange(int a, int b, int c) {
		return Math.abs(((a + c) / 2.0) - b);
	}
}