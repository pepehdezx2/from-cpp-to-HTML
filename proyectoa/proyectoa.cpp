//  A01381334 José Antonio Hernández Hernández
//  main.cpp
//  proyectoa
//
//  Created by Jose Antonio on 08/02/18.
//  Copyright © 2018 Jose Antonio. All rights reserved.
//  algoritmo
//  declaracion de variables
//  pedir y guardar el nombre del archivo a leer
//  guardar el nombre del archivo en 2 extensiones para mas tarde ponerle ya sea o html o coo
//  insertar la extension del archivo a cada string de extension ya guardado
//  declaracion de archivos de entrada y salida ya con su extension (cpp para entrada, html para salida)
//  escribir en el archivo de salida el inicio de la documentacion
//  ciclo que lee hasta que se termina el programa
//  lee lo primero de cada renglon y lo guarda en un string
//  lo compara con la funcion y escribe en un archivo de salida la documentacion para html
//  en otro string lee todo el renglon despues del tipo de doc que se usara en el html y lo guarda para escribirlo en el archivo de salida
//  al terminar el ciclo cierra los archivos de entrada y salida

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    // declaracion de variables...
    string archivo, extensiona, extensionb, texto, tipo;
    long largo, posiciona;
    // pedir el nombre del archivo a leer/ crear...
    cout << "nombre del archivo" << endl;
    // conseguir el nombre del archivo...
    getline(cin, archivo);
    // conseguir el largo del string...
    largo=archivo.length();
    // guardar en dos variables el nombre, para poder agregar la extension y tener el nombre de el archivo de entrada y salida...
    extensiona=archivo;
    extensionb=archivo;
    // agregar extensiones .cpp y html respectivamente con el mismo nombre...
    extensiona.insert(largo,".cpp");
    extensionb.insert(largo,".html");
    // funciones que leen y crean un programa con el nombre dado...
    ifstream archivoentrada(extensiona);
    ofstream archivosalida(extensionb);
    // funcion que escribe en el archivo de salida la documentacion html...
    archivosalida << "<!DOCTYPE html>\n<html>\n<head>\n<title>\nDocumentaci&oacuten del archivo " << extensiona << "\n</title> \n</head>\n<body>\n";
    // ciclo que lee el archivo de entrada y termina hasta que se acaba el archivo...
    while (!archivoentrada.eof()) {
        // consigue un string hasta el espacio...
        archivoentrada >> tipo;
        // busca si encuentra en el archivo "*/", que es con lo que inicia si habra algo de programacion para el html...
                posiciona=tipo.find("*/");
                if (posiciona == -1){
                    // funciones que leen la primera palabra y comparan que tipo de funcion html se usara...
                    if (tipo == "@progName"){
                        getline(archivoentrada, texto);
                        archivosalida << "\n <h2>\n  Programa: "  << texto << "<br>\n </h2>" << endl;
                    }
                    if (tipo == "@desc"){
                        getline(archivoentrada, texto);
                        archivosalida << "\n <strong>\n  Descripci&oacute;n: </strong>" << texto << "<br>" << endl;
                    }
                    if (tipo == "@author"){
                        getline(archivoentrada, texto);
                        archivosalida << "\n <strong>\n  Autor: </strong>" << texto << "<br>" << endl;
                    }
                    if (tipo == "@date"){
                        getline(archivoentrada, texto);
                        archivosalida << "\n <strong>\n  Fecha de elaboraci&oacute;n: </strong>" << texto << "<br>" << endl;
                    }
                    if (tipo == "@param"){
                        getline(archivoentrada, texto);
                        archivosalida << "\n <strong>\n  Par&aacute;metro: </strong>" << texto << "<br>" << endl;
                    }
                    if (tipo == "@return"){
                        getline(archivoentrada, texto);
                        archivosalida << "\n <strong>\n  Valor de retorno: </strong>" << texto << "<br>" << endl;
                    }
                    if (tipo == "@funcName"){
                        getline(archivoentrada, texto);
                        archivosalida << "\n <h3>\n \n <strong>\n Funci&oacute;n: </strong>" << texto << "<br>\n </h3>" << endl;
                    }
                }
    // si termina escribe una linea a lo largo de la pagina html...
        else
             archivosalida << "<br> \n <hr>\n" << endl;
    }
    // cierra los archivos...
    archivoentrada.close();
    archivosalida.close();
    return 0;
}

