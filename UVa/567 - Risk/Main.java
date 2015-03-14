import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * 
 * UVA problem 567 - Risk
 * 
 * @author Jhonjhon_123
 * 
 */

public class Main {

	private static final boolean DEB = false;
	private static BufferedReader br;
	private static StringBuilder sb = new StringBuilder();
	private final static String NEWLINE = System.lineSeparator();

	private static int adj[][] = new int[20][20];

	private static int testSet = 1;

	public static void main(String[] args) throws Exception {
		File file = new File("input.txt");
		if (file.exists())
			br = new BufferedReader(new InputStreamReader(new FileInputStream(
					file)));
		else
			br = new BufferedReader(new InputStreamReader(System.in));

		resetRisk();

		int i = 0;
		int val = 0;
		int testCases = 0;

		int from = 0;
		int to = 0;

		StringTokenizer st;

		// risk games
		do {

			// tenemos lineas?
			if (!br.ready())
				break;

			// Obtener sus vecinos
			if (DEB)
				System.out.println("--" + i);
			st = new StringTokenizer(br.readLine().trim(), " ");
			// ignorar el primero
			st.nextToken();
			// procesar sus vecinos
			while (st.hasMoreTokens()) {
				val = Integer.parseInt(st.nextToken()) - 1;
				adj[i][val] = adj[val][i] = 1;
			}

			// Primer risk
			if (i == 18) {

				if (DEB)
					printAdj();

				// Solve
				floydwarshall(adj);

				// print actual risk
				sb.append("Test Set #");
				sb.append(testSet);
				sb.append(NEWLINE);

				// Obtener numero de casos de prueva
				testCases = Integer.parseInt(br.readLine().trim());
				// procesar casos de prueva
				for (int j = 0; j < testCases; j++) {
					st = new StringTokenizer(br.readLine().trim(), " ");
					from = Integer.parseInt(st.nextToken());
					to = Integer.parseInt(st.nextToken());
					solveRisk(from, to);

				}

				System.out.println(sb.toString());
				// Volver a empezar
				resetRisk();
				sb.setLength(0);
				testSet++;
				i = 0;
			} else
				i++;
		} while (true);

		br.close();
	}

	private static void resetRisk() {
		// Llenar matriz
		for (int[] sub : adj)
			Arrays.fill(sub, 30);
	}

	private static void solveRisk(int from, int to) {
		sb.append(String.format("%2s", from));
		sb.append(" to ");
		sb.append(String.format("%2s", to));
		sb.append(": ");
		sb.append(adj[from - 1][to - 1]);
		sb.append(NEWLINE);
	}

	public static void floydwarshall(int[][] path) {
		for (int k = 0; k < path.length; k++) {
			for (int i = 0; i < path.length; i++) {
				for (int j = 0; j < path.length; j++) {
					path[i][j] = Math.min(path[i][j], path[i][k] + path[k][j]);
				}
			}
		}
	}

	private static void printAdj() {
		for (int[] sub : adj) {
			for (int i : sub) {
				System.out.print(i + "\t");
			}
			System.out.println();
		}
	}

}
