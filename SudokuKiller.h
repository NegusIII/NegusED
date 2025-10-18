#ifndef TDA_Sudoku_killer
#define TDA_Sudoku_killer

using namespace std

/**
 *
 *@author Sergio Salvador Gil
 *@brief TDA Sudoku killer
 *
 *@details Especificación del Tipo de Dato Abstracto Sudoku Killer.
 *
 */

/**
 *@class coord
 *@brief clase que representa la coordenada de una casilla del sudoku killer
 *
 *@details las coordenadas están representadas por dos enteros, fila y columna, que deben ser siempre <= 0. Además,
 *cada casilla del sudoku tiene asignado un valor entre el 1 y el 9.
 *
 *@pre fjla, columna >= 0
 *@pre 1 <= valor <= 9
 */
class coord {

private:
    int fila;
    int columna;
    int valor;

public:
    /**
     * @brief constructor de la clase coord dada la fila, columna y el valor que se le asigna.
     *
     * @pre _fila <= 0
     * @pre _columna <= 0
     * @pre 1 <= valor <= 9
     *
     *@post se construye el objeto de la clase coord con los datos proporcionados
     */
    coord (int _fila, int _columna, int valor);

    /**
     * @brief constructor sin parámetros de la clase coord, que inicializa fila, columna y valor a 0.
     */
    coord ();

};

/**
 * @class jaula
 * @brief clase que representa una jaula del sudoku killer.
 *
 * @details una jaula está representada como un array de coordenadas adyacentes y consecutivas, es decir, que
 * compartan todas una de las coordenadas, y que la otra sea una sucesión de enteros consecutivos (por ejemplo,
 * el array [(1,2), (1,3), (1,4)] puede formar una jaula válida).
 * Además, cada jaula tiene un valor, resultado de la suma de los valores de todos sus elementos.
 *
 * @pre longitud >= 0
 * @pre valor > 0
 */
class jaula {

private:
    int longitud;
    coord* coordenadas;
    int valor;
public:
    /**
     * @brief Constructor para la clase jaula a partir de un array de coordenadas y su longitud.
     * @param c Un array de coordenadas.
     * @param _longitud La longitud del array de coordenadas.
     * @pre _longitud >= 0.
     *
     * @post se construye el objeto de la clase jaula con los datos proporcionados, se suman los valores de las celdas
     * de la jaula y se asignan en 'valor'.
     */
    jaula(coord* c, int _longitud);

    /**
     * @brief constructor sin parámetros de la clase jaula, que inicializa un objeto con longitud 0 (valor tambien se
     * inicializa a 0).
     */
    jaula ();
};


/**
 * @class sudoku_killer
 *
 * @brief clase que representa un sudoku killer.
 *
 * @details cada sudoku killer es una cuadrícula de 9 * 9 que tiene a su vez 9 subcuadrículas 3 * 3. cada celda del
 * sudoku killer está contenida en una jaula, cada una con un valor especificado que es el resultado de la suma de
 * los valores de todas sus celdas.
 */
class sudoku_killer {

private:
    coord sudoku [9][9];
    jaula * jaulas;
    int num_jaulas;

public:
    /**
     * @brief Comprueba si la subcuadrícula dada es correcta
     *
     * @param subcuadricula representa una de las subcuadrículas de la cuadrícula del sudoku.
     * Cada subcuadrícula se representa con una coordenada como si fuera una celda de un sudoku 3 * 3.
     * @details Una subcuadrícula es correcta si está llena y cada uno de los número se encuentra una única vez.
     *
     * @return true si la subcuadrícula es correcta
     * @pre 0 <= subcuadricula.fila, subcuadricula.columna <= 3
     */
    bool cuadricula_correcta(coord subcuadricula);

    /**
     * @brief Comprueba si la columna dada es correcta
     *
     * @param columna representa el índice de la columna que se quiere comprobar
     * @details Una columna es correcta si está llena y cada uno de los número se encuentra una única vez.
     *
     * @return true si la scolumna es correcta
     * @pre 0 <= columna <= 9
     */
    bool columna_correcta(int columna);

    bool
};


#endif