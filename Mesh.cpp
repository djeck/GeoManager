#include "Mesh.hpp"

Mesh::Mesh()
{
  m_index = glGenLists(1);
  
  transformShape();
}

Mesh::~Mesh()
{
  glDeleteLists(m_index, 1);
}

void Mesh::transformShape()
{
    glNewList(m_index, GL_COMPILE);
    
    glBegin(GL_QUADS);
    
    glColor3ub(255,0,0); //face rouge
    glVertex3d(1,+1,+1);
    glVertex3d(1,+1,-1);
    glVertex3d(-1,+1,-1);
    glVertex3d(-1,+1,+1);

    glColor3ub(0,255,0); //face verte
    glVertex3d(1,-1,1);
    glVertex3d(1,-1,-1);
    glVertex3d(1,1,-1);
    glVertex3d(1,1,1);

    glColor3ub(0,0,255); //face bleue
    glVertex3d(-1,-1,1);
    glVertex3d(-1,-1,-1);
    glVertex3d(1,-1,-1);
    glVertex3d(1,-1,1);

    glColor3ub(255,255,0); //face jaune
    glVertex3d(-1,1,1);
    glVertex3d(-1,1,-1);
    glVertex3d(-1,-1,-1);
    glVertex3d(-1,-1,1);

    glColor3ub(0,255,255); //face cyan
    glVertex3d(1,1,-1);
    glVertex3d(1,-1,-1);
    glVertex3d(-1,-1,-1);
    glVertex3d(-1,1,-1);

    glColor3ub(255,0,255); //face magenta
    glVertex3d(1,-1,1);
    glVertex3d(1,1,1);
    glVertex3d(-1,1,1);
    glVertex3d(-1,-1,1);
    
    glEnd();
    
    glEndList();
}


void Mesh::draw(sf::Vector3f position,sf::Vector3f rotation)
{
	glPushMatrix();
  
	glRotated((double)rotation.x,1,0,0);
	glRotated((double)rotation.y,0,1,0);
	glRotated((double)rotation.z,0,0,1);
    
	glTranslatef(position.x, position.y, position.z);
    
	glCallList(m_index);

	glPopMatrix();
    
}