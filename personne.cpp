#include "personne.hpp"

Personne::Personne()
{
  m_index = glGenLists(1);
  
  m_rotate.x=0;
  m_rotate.x=0;
  m_rotate.x=0;
  m_drotate.x=0;
  m_drotate.x=0;
  m_drotate.x=0;
  m_ddrotate.x=0;
  m_ddrotate.x=0;
  m_ddrotate.x=0;
  
  transformShape();
}

Personne::~Personne()
{
  glDeleteLists(m_index, 1);
}

void Personne::transformShape()
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


void Personne::draw()
{
  glPushMatrix();
  
    glRotated((double)m_rotate.x,1,0,0);
    glRotated((double)m_rotate.y,0,1,0);
    glRotated((double)m_rotate.z,0,0,1);
    
    glTranslatef(m_position.x, m_position.y, m_position.z);
    
    glCallList(m_index);

  glPopMatrix();
    
}


void Personne::setRotation(sf::Vector3f rotation)
{
  m_rotate=rotation;
}

void Personne::setRotationMV(sf::Vector3f rotation)
{
  m_drotate=rotation;
}

void Personne::setRotationMVAcc(sf::Vector3f rotation)
{
  m_ddrotate=rotation;
}


sf::Vector3f Personne::getRotation()
{
  return m_rotate;
}

void Personne::calcul()
{
  m_elapsed = m_clock.restart();
  
  m_dposition += m_ddposition*m_elapsed.asSeconds();
  m_position += m_dposition*m_elapsed.asSeconds();
  
  m_drotate += m_ddrotate*m_elapsed.asSeconds();
  m_rotate += m_drotate*m_elapsed.asSeconds();
}
void Personne::setSelected(bool select)
{
  m_selected=select;
}
bool Personne::isSelected()
{
  return m_selected;
}
