import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 10055 Hashmat the Brave Warrior
 */
public class Main {

	// private static final boolean DEB = false;

	private static BufferedReader br;

	// private static StringBuilder sb = new StringBuilder();
	// private final static String NEWLINE = System.lineSeparator();

	public static void main(String[] args) throws IOException {

		// read in
		File file = new File("input.txt");
		if (file.exists())
			br = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
		else
			br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st;

		// main
		do {
			// have lines?
			if (!br.ready())
				break;

			/*
			 * your code here!
			 */

			st = new StringTokenizer(br.readLine().trim(), " ");

			System.out.println(Math.abs(Long.parseLong(st.nextToken()) - Long.parseLong(st.nextToken())));

		} while (true);

		// close out
		br.close();

	}

}
