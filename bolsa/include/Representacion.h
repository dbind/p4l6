#ifndef REPRESENTACION_H
#define REPRESENTACION_H

#include <string>


class Representacion
{
    private:
        char categoria;
        string patologia;
        string etiqueta;
        string etiquetaCategoria;

    public:
        Representacion();
        virtual ~Representacion();

        char getCategoria();
        string getPatologia();
        string getEtiqueta();
        string getEtiquetaCategoria();
        setCategoria(char categoria);
        setPatologia(string patologia);
        setEtiqueta(string etiqueta);
        setEtiquetaCategoria(string etiquetaCategoria);

        string obtenerCodigoRepresentacion();
};

#endif // REPRESENTACION_H
