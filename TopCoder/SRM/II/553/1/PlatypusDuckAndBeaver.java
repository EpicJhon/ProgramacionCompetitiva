/**
* PlatypusDuckAndBeaver	553	II	1
*/

public class PlatypusDuckAndBeaver {

	public static int minimumAnimals(int webbedFeet, int duckBills, int beaverTails) {
		if (duckBills > 0 && webbedFeet > 0 && beaverTails == 0)
			if ((duckBills + webbedFeet) % 3 == 0)
				return (duckBills + webbedFeet) / 3;
		if (beaverTails > 0 && webbedFeet > 0 && duckBills == 0)
			if ((beaverTails + webbedFeet) % 5 == 0)
				return (beaverTails + webbedFeet) / 5;

		int animals = webbedFeet + duckBills + beaverTails;
		if (animals % 6 == 0)
			return animals / 6;
		if (animals % 8 == 0)
			return (animals / 8) * 2;
		if (animals % 9 == 0)
			return (animals / 9) * 2;
		if (animals % 11 == 0)
			return (animals / 11) * 2;
		if (animals % 14 == 0)
			return (animals / 14) * 3;

		return 0;
	}
}