public class BishopMove {

  public int howManyMoves(int r1, int c1, int r2, int c2) {
 
		 // calculamos la diferencia de recorrido en "x" y "y"
         int rowDiff = Math.abs(r2 - r1);
         int colDiff = Math.abs(c2 - c1);
 
		 // si estamos en la misma posision
         if ((rowDiff == 0) && (colDiff == 0)) return 0;

		// si la relacion de movimientos es igual, entonces es solo un movimiento
         if (rowDiff == colDiff) return 1;

		// si la diferencia entre movidas no es una relacion de 2, entonces no ahi movimiento posible
		if (((rowDiff - colDiff) % 2) != 0) return -1;

		 // en cualquier otro caso el movimiento del alfil siempre es de 2
         return 2;
 
  }
 }