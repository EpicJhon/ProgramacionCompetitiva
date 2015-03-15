/**
*  Single Round Match 512 Round 1 - Division II, Level One
*/

public class MarbleDecoration {

	public static int maxLength(int R, int G, int B) {

		int maxx = 0;
		int tmp = 0;
		int max = 0;
		int limit = 0;

		// R & G
		max = (R > G) ? R : G;
		limit = (R > G) ? G : R;

		if (max == limit)
			maxx = max * 2;
		else
			maxx = (limit * 2) + 1;

		// R & B
		max = (R > B) ? R : B;
		limit = (R > B) ? B : R;

		if (max == limit) {
			tmp = max * 2;
			maxx = (tmp > maxx) ? tmp : maxx;
		} else {
			tmp = (limit * 2) + 1;
			maxx = (tmp > maxx) ? tmp : maxx;
		}

		// G & B
		max = (G > B) ? G : B;
		limit = (R > B) ? B : G;

		if (max == limit) {
			tmp = max * 2;
			maxx = (tmp > maxx) ? tmp : maxx;
		} else {
			tmp = (limit * 2) + 1;
			maxx = (tmp > maxx) ? tmp : maxx;
		}

		return maxx;

	}
}