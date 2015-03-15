/**
*      Member Single Round Match 503 Round 1 - Division II, Level One
*/

public class ToastXRaspberry {

	public static int apply(int upper_limit, int layer_count) {

		if (upper_limit > layer_count || upper_limit == layer_count)
			return 1;
		else {
			int layers = layer_count / upper_limit;
			return (layers * upper_limit == layer_count) ? layers : layers + 1;
		}

	}
}