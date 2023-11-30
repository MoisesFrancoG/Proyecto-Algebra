#include<iostream>
#include <vector>

using namespace std; // Codigo hecho por Moises Franco Gtz (233312) y Usmar Alfredo Santiago Gonzales (233413)


int pedir_ecuaciones_matriz(int filas) {
    cout << "Digite el número de ecuaciones que tiene su sistema: ";
    cin >> filas;

    return filas;
}

void ingresar_Matriz(int filas, int columnas, float matriz[100][100]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (j < columnas - 1) {
            cout << "En ecuacion " << i + 1 <<" Digite variable " <<j + 1 <<": ";
            cin >> matriz[i][j];
            } else {
                cout << "En ecuacion " << i + 1 << " Digite constante " << i + 1 << ": ";
                cin >> matriz[i][j];
            }
        }
    }
    cout << endl;
}

void imprimir_Matriz(int filas, int columnas, float matriz[100][100]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void gauss_jordan(int filas, int columnas, float matriz[100][100]) {
    float pivote;
    float auxiliar;
    for(int i = 0; i < filas; i ++) {

        pivote = matriz[i][i];

        for(int k = 0; k < columnas; k ++) {
            matriz[i][k] = matriz[i][k] / pivote;
        }
       
        imprimir_Matriz(filas,columnas,matriz);
        cout << endl;

         for(int j = 0; j < filas; j ++) {
            if(i!=j) {
                auxiliar = matriz[j][i];

                for(int p = 0; p < columnas; p++) {
                    matriz[j][p] = matriz[j][p] - auxiliar * matriz[i][p];
                }
                
                imprimir_Matriz(filas,columnas,matriz);
                cout << endl;
            }
        }
    }
}

// Función para sumar dos matrices
vector<vector<int>> sumarMatrices(const vector<vector<int>>& matrizA, const vector<vector<int>>& matrizB) {
    int filas = matrizA.size();
    int columnas = matrizA[0].size();

    vector<vector<int>> resultado(filas, vector<int>(columnas, 0));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    return resultado;
}

// Función para restar dos matrices
vector<vector<int>> restarMatrices(const vector<vector<int>>& matrizA, const vector<vector<int>>& matrizB) {
    int filas = matrizA.size();
    int columnas = matrizA[0].size();

    vector<vector<int>> resultado(filas, vector<int>(columnas, 0));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }

    return resultado;
}

int main() {
	
	int opcion;
	float matriz[100][100];
	int numero;
	
	do {
		cout << "------------------------------------" << endl;
		cout << "|            UAM APP               |" << endl;
		cout << "------------------------------------" << endl;
		cout << "Selecione la opcion correspondiente" << endl;
		cout << "1. Resolver sistemas de ecuaciones." << endl;
		cout << "2. Matriz Inversa." << endl;
		cout << "3. Suma y Resta de Matrices." << endl;
		cout << "4. Matriz Transpuesta." << endl;
		cout << "5. Matriz Adjunta." << endl;
		cout << "6. Salir." << endl;
		cin >> opcion;
		cout << endl;
	
		switch (opcion) {
			case 1: {
				
				cout <<" ------------------------------" << endl;
				cout <<" | BIENVENIDO A UAM APP       |" << endl;
				cout <<" ------------------------------" << endl;
				cout <<"Resolucion de sistemas de ecuaciones por Gauss-Jordan" << endl << endl;
				int filas = pedir_ecuaciones_matriz(filas);
	    		int columnas = filas + 1;
	
			    ingresar_Matriz(filas,columnas,matriz);
			
			    imprimir_Matriz(filas,columnas,matriz);
			
			    gauss_jordan(filas,columnas,matriz);
				break;
			}
			
			case 2: {
				cout <<" ------------------------------" << endl;
				cout <<" | BIENVENIDO A UAM APP       |" << endl;
				cout <<" ------------------------------" << endl;
				cout <<"Mostrar la inversa de una matriz" << endl << endl;
				cout <<"Introduzca el numero de filas y columnas de la matriz nxn: ";
				cin >> numero;
				
				float A[numero][numero];
				float I[numero][numero];
				float aux;
				float pivote;
				
				for(int i = 0; i < numero; i++) {
					for (int j = 0; j < numero; j++) {
						
						cout << "Introduzca su matriz: " << "[" << i << "]" << "[" << j << "]: ";
						cin >> A[i][j];
						I[i][j] = 0;
						
						if (i == j) {
							I[i][j] = 1;
						}
					}
				} cout << endl;
				
				cout << "Matriz Original" << endl;
				for(int i = 0; i < numero; i++){
					for(int j = 0; j < numero; j++) {
						
						cout << A[i][j] << "\t";
						
					} cout << endl;
				} cout << endl;
				
				
				cout << "La matriz inversa es" << endl;
				for(int i = 0; i < numero; i++) {
					
					pivote = A[i][i];
					
					for(int k = 0; k < numero; k++) {
						
						A[i][k] = A[i][k] / pivote;
						I[i][k] = I[i][k] / pivote;
						
					}
					
					for(int j = 0; j < numero; j++) {
						
						if (i != j) {
							
							aux = A[j][i];
							
							for (int k = 0; k < numero; k++) {
								
								A[j][k] = A[j][k] - aux * A[i][k];
								I[j][k] = I[j][k] - aux * I[i][k];
							}
						}
					}
				}
				
				for(int i = 0; i < numero; i++){
					for(int j = 0; j < numero; j++) {
						
						cout << A[i][j] << "\t";
						
					} cout << endl;
				} cout << endl;
				
				for(int i = 0; i < numero; i++){
					for(int j = 0; j < numero; j++) {
						
						cout << I[i][j] << "\t";
						
					} cout << endl;
				} cout << endl;
				break;
			}
			
			case 3: {
				int numMatrices;
    			int filas, columnas;
    			
				cout <<" ------------------------------" << endl;
				cout <<" | BIENVENIDO A UAM APP       |" << endl;
				cout <<" ------------------------------" << endl;
				cout <<"Sumar o restar matrices" << endl << endl;
			    // Solicitar el tamaño de las matrices
			    cout << "Ingrese el número de filas de las matrices: ";
			    cin >> filas;
			
			    cout << "Ingrese el número de columnas de las matrices: ";
			    cin >> columnas;
			    cout << endl;
			
			    // Solicitar el número de matrices
			    cout << "Ingrese el número de matrices (entre 2 y 100): ";
			    cin >> numMatrices;
			    cout << endl;
			
			    if (numMatrices < 2 || numMatrices > 100) {
			        cout << "Número de matrices no válido. Debe estar entre 2 y 100." << endl;
			        return 1;
			    }
			
			    // Inicializar un vector de matrices
			    vector<vector<vector<int>>> matrices(numMatrices, vector<vector<int>>(filas, vector<int>(columnas, 0)));
			
			    // Solicitar y almacenar las matrices
			    for (int k = 0; k < numMatrices; ++k) {
			        cout << "Ingrese los elementos de la matriz " << k + 1 << ":\n";
			        for (int i = 0; i < filas; ++i) {
			            for (int j = 0; j < columnas; ++j) {
			                cout << "Elemento [" << i << "] [" << j << "]: ";
			                cin >> matrices[k][i][j];
			            }
			        } cout << endl;
			    } cout << endl;
			
			    // Elegir la operación
			    int opcion;
			    cout << "Seleccione la operación a realizar:\n";
			    cout << "1. Suma de matrices\n";
			    cout << "2. Resta de matrices\n";
			    cout << "Ingrese el número de la operación: ";
			    cin >> opcion;
			    cout << endl;
			
			    if (opcion != 1 && opcion != 2) {
			        cout << "Opción no válida. Saliendo del programa." << endl;
			    } cout << endl;
			
			    // Realizar la operación seleccionada
			    vector<vector<int>> resultado;
			    if (opcion == 1) {
			        resultado = matrices[0]; // Inicializar con la primera matriz
			        for (int i = 1; i < numMatrices; ++i) {
			            resultado = sumarMatrices(resultado, matrices[i]);
			        }
			    } else {
			        resultado = matrices[0]; // Inicializar con la primera matriz
			        for (int i = 1; i < numMatrices; ++i) {
			            resultado = restarMatrices(resultado, matrices[i]);
			        }
			    } cout << endl;
			
			    // Imprimir el resultado
			    cout << "El resultado de la operación es:\n";
			    for (const auto& fila : resultado) {
			        for (int elemento : fila) {
			            cout << "\t" << elemento << " ";
			        }
			        cout << endl;
			    } cout << endl;

				break;
			}  
			
			case 4 : {
				int filCol = 0;
						cout <<" ------------------------------" << endl;
						cout <<" | BIENVENIDO A UAM APP       |" << endl;
						cout <<" ------------------------------" << endl;
						cout <<"Matriz transpuesta" << endl << endl;
						
						cout << "Ingrese el tamaño de su matriz filas X columnas: " ;
						cin >> filCol;
						
						float matrix[filCol][filCol];
						
						for(int i = 0; i < filCol; i++){
							for(int j = 0; j < filCol; j++) {
								cout << "Ingrese los numeros de su matriz [" << i << "] [" << j << "]: ";
								cin >> matrix[i][j];
							}
						} cout << endl;
						
						cout << "Matriz ingresada" << endl;
						for(int i = 0; i < filCol; i++) {
							for(int j = 0; j < filCol; j++) {
								cout << matrix[i][j] << "\t";
							} cout << endl;
						} cout << endl;

						cout << "Matriz Transpuesta" << endl;
						for(int j = 0; j < filCol; j++) {
							for(int i = 0; i < filCol; i++) {
								cout << matrix[i][j] << "\t";
							} cout << endl;
						} cout << endl;
				break;
			}
			
			case 5: {	
						
						cout <<" ------------------------------" << endl;
						cout <<" | BIENVENIDO A UAM APP       |" << endl;
						cout <<" ------------------------------" << endl;
						cout << "Calcular la adjunta de una matriz." << endl;
		                int tam;
		                cout << "Ingrese la cantidad de filas y columnas de su matriz: ";
		                cin >> tam;
		
		                vector<vector<double>> matriz(tam, vector<double>(tam));
		                vector<vector<double>> matrizAdjunta(tam, vector<double>(tam));
		
		                for (int i = 0; i < tam; i++) {
		                    for (int j = 0; j < tam; j++) {
		                        cout << "Ingrese el valor [" << i << "] [" << j << "] de su matriz: ";
		                        cin >> matriz[i][j];
		                    }
		                } cout << endl;
		                
		                cout << "Matriz Original" << endl;
		                for (int i = 0; i < tam; ++i) {
		                    for (int j = 0; j < tam; ++j) {
		                        cout << matriz[i][j] << "\t";
		                    }
		                    cout << endl;
		                }cout << endl;
		
		                // Cálculo de la matriz transpuesta
		                cout << "Matriz Original Transpuesta" << endl;
		                for (int j = 0; j < tam; ++j) {
		                    for (int i = 0; i < tam; ++i) {
		                        cout << matriz[i][j] << "\t";
		                    }
		                    cout << endl;
		                }cout << endl;
		                
		                // Cálculo de la matriz adjunta
		                cout << "Matriz Intermediaria:" << endl;
		                for (int i = 0; i < tam; ++i) {
		                    for (int j = 0; j < tam; ++j) {
		                        // Calcular el cofactor
		                        int sign = (i + j) % 2 == 0 ? 1 : -1;
		                        vector<vector<double>> matrizAux(tam - 1, vector<double>(tam - 1));
		                        for (int x = 0; x < tam; x++) {
		                            for (int y = 0; y < tam; y++) {
		                                if (x != i && y != j) {
		                                    matrizAux[x < i ? x : x - 1][y < j ? y : y - 1] = matriz[x][y];
		                                }
		                            }
		                        }
		                        double subdeterminante = (matrizAux[0][0] * matrizAux[1][1]) - (matrizAux[1][0] * matrizAux[0][1]);
		                        double cofactor = sign * subdeterminante;
		                        matrizAdjunta[i][j] = cofactor;
		                        cout << cofactor << "\t";
		                    }
		                    cout << endl;
		                } cout << endl;
		                
		                
					    cout << "Matriz Adjunta Final" << endl;
					    for (int j = 0; j < tam; ++j) {
					        for (int i = 0; i < tam; ++i) {
					            cout << matrizAdjunta[i][j] << "\t";
					        }
					        cout << endl;
					    }	cout << endl;
				break;
			}
			
			case 6 : {
				break;
			}
			
			default : {
				cout << "Opcion " << opcion << " no esta dentro del menu." << endl;
				cout << "Ingrese una opcion valida." << endl << endl; 
				break;
			}
		}
	} while (opcion != 6);

    return 0;
}
