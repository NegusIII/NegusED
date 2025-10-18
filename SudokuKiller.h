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
 *@pre fila, columna >= 0
 */
class coord {

private:
    int fila;
    int columna;

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
    coord (int _fila, int _columna);

    /**
     * @brief constructor sin parámetros de la clase coord, que inicializa fila, columna y valor a 0.
     */
    coord ();

    /**
     * @return fila
     */
    int get_fila() const;
    /**
     * @return columna
     */
    int get_columna() const;

};

/**
 * @class jaula
 * @brief clase que representa una jaula del sudoku killer.
 *
 * @details una jaula está representada con una posición de inicio, una dirección (horizontal, expandiendose hacia la
 * derecha, o vertical, si no es horizontal y se desplaza hacia abajo), y su longitud.
 * Además, cada jaula tiene un valor, que es correcto si es el resultado de la suma de los valores de todos sus elementos.
 *
 * @pre longitud >= 0
 * @pre valor > 0
 */
class jaula {

private:
    coord inicio;
    int longitud;
    int valor;
    bool horizontal;
public:
    /**
     * @brief Constructor para la clase jaula a partir de su valor, su longitud y su dirección.
     * @param valor, el valor de la jaula
     * @param _longitud La longitud del array de coordenadas.
     * @pre _longitud >= 0.
     *
     * @post se construye el objeto de la clase jaula con los datos proporcionados.
     */
    jaula(coord _inicio, int _valor int _longitud, bool _horizontal);

    /**
     * @brief constructor sin parámetros de la clase jaula, que inicializa un objeto con longitud 0 (valor tambien se
     * inicializa a 0).
     */
    jaula ();

    /**
     * @return inicio
     */
    coord get_inicio() const;
    /**
     * @return longitud
     */
    int get_longitud() const;
    /**
     * @return valor
     */
    int get_valor() const;
    /**
     * @return horizontal
     */
    bool get_horizontal() const;

};


/**
 * @class sudoku_killer
 *
 * @brief clase que representa un sudoku killer.
 *
 * @details cada sudoku killer es una cuadrícula de 9 * 9 que tiene a su vez 9 subcuadrículas 3 * 3. cada celda del
 * sudoku killer está contenida en una jaula, cada una con un valor especificado que es el resultado de la suma de
 * los valores de todas sus celdas.
 *
 * @pre todas las casillas tienen que estar incluídas en una jaula y solo una.
 * @pre 1 <= valores <= 9.
 */
class sudoku_killer {

private:
    int valores [9][9];
    jaula * jaulas;
    int num_jaulas;

public:
    /**
     * @brief constructor sin parámetros
     * @details inicializa el objeto con todas las casillas con valor 0, y sin jaulas.
     */
    sudoku_killer();

    /**
     * @brief constructor del sudoku killer con un array de valores y uno de jaulas
     * @param valores array con los valores del sudoku_killer
     */
    sudoku_killer(const int* valores, const jaula* _jaulas, int _num_jaulas);
    /**
     *@brief devuelve el valor de una casilla del sudoku killer
     *
     * @pre 0 <= fila <= 9
     * @pre 0 <= columna <= 9
     *
     * @return valores [fila][columna]
     */
    int get_valor(int fila, int columna);
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

    /**
     * @brief comprueba que una jaula del sudoku killer sea correcta
     * @details una jaula es correcta si las componentes suman su valor. Por ejemplo, una jaula con valor 10, que
     * tenga como inicio la casilla (0,0) y de longitud horizontal 2, es correcta únicamente si
     * valores[0][0] + valores[0][1] = 10
     * @return true si la jaula es correcta
     */
    bool jaula_correcta(const jaula & _jaula);

    /**
     * @brief comprueba si el sudoku_killer está resuelto correctamente.
     * @details El sudoku_killer es correcto únicamente si todas sus columnas son correctas, todas sus subcuadrículas
     * son correctas, y además si todas sus jaulas son tambien correctas.
     *
     * @return true si el sudoku es correcto.
     */
    bool sudoku_correcto();
};


#endif