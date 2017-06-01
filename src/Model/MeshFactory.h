#ifndef GLPRESS_MESHFACTORY_H
#define GLPRESS_MESHFACTORY_H


#include "Mesh.h"

class MeshFactory {
public:

    static std::shared_ptr<Mesh> createPlane(GLfloat w, GLfloat d);

    static std::shared_ptr<Mesh> createPlane(GLfloat w, GLfloat d, GLfloat uScale, GLfloat vScale);


    static std::shared_ptr<Mesh> createCube(GLfloat w, GLfloat h, GLfloat d);

    static std::shared_ptr<Mesh> createCube(GLfloat w, GLfloat h, GLfloat d,
                                            GLfloat suScale, GLfloat svScale,
                                            GLfloat cuScale, GLfloat cvScale);

    static std::shared_ptr<Mesh> createCylinder(GLfloat r, GLfloat h, GLuint sides);

    static std::shared_ptr<Mesh> loadFromFile(std::string fileName);

    static std::shared_ptr<Mesh> loadFromObjFile(std::string fileName);

    static void genearateCodeFrmObj(std::string fileName);
};


#endif //GLPRESS_MESHFACTORY_H
