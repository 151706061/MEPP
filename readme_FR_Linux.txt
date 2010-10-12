///////////////////////////////////////////////////////////////////////////
// Author: Martial TOLA
// Year: 2010
// CNRS-Lyon, LIRIS UMR 5205
///////////////////////////////////////////////////////////////////////////

Marche � suivre pour Mepp sous Ubuntu 9.10, 10.04 ou 10.10 :
------------------------------------------------------------

1) installer Ubuntu 9.10, 10.04 ou 10.10

2) faire la mise � jour de la distribution et des paquets d�j� install�s

3) installer les paquets suivants:
sudo apt-get update
sudo apt-get install filezilla subversion unrar libcgal-dev qtcreator libqglviewer-qt4-dev g++ cmake-gui libglew-dev

-------------------------------
Suivant votre version d'Ubuntu:
-------------------------------
4a) sous Ubuntu 9.10 cr�er 2 liens:
cd /usr/lib
sudo ln -s libqglviewer-qt4.so libQGLViewer.so
cd /usr/include
sudo ln -s qglviewer-qt4 QGLViewer

ou

4b) sous Ubuntu 10.04 cr�er 1 lien:
cd /usr/lib
sudo ln -s libqglviewer-qt4.so libQGLViewer.so

ou

4c) sous Ubuntu 10.10, rien � faire
-----------------------------------------------

5) t�l�charger les sources de Mepp:
svn checkout https://nom-du-d�veloppeur@scm.gforge.liris.cnrs.fr/svnroot/mepp/trunk

6a) compiler Mepp avec CMake et Makefile:
se positionner dans trunk, puis,
 - mkdir build; cd build
 - pour une version Release: "cmake .." puis make
 - pour une version Debug: "cmake .. -DCMAKE_BUILD_TYPE=Debug" (2 fois pour la prise en compte du mode Debug) puis make
note: vous pouvez �galement utiliser la version "graphique" de CMake: cmake-gui

ou

6b) compiler Mepp avec CMake et Qt Creator:
CMake (ou CMake-gui) est capable de g�n�rer (pour le moment) sous Linux des Makefiles Unix ainsi que des projets Code::Blocks ou encore KDevelop,
mais malheureusement pas encore des projets Qt Creator (.pro).
Qt Creator sait par contre interpr�ter directement le CMakeLists.txt de cmake
pour g�n�rer les projets Qt Creator (.pro).

Donc, pour g�n�rer les projets Qt Creator (.pro), voici la marche � suivre au sein de Qt Creator:

Ouvrir un fichier et choisir en bas 'Fichier de projet CMake'
puis choisir le CMakeLists.txt de la racine du trunk puis cliquer sur 'suivant'
puis dans 'Arguments' mettre -DCMAKE_BUILD_TYPE=Debug pour g�n�rer les projets Qt Creator (.pro) en Debug
ou rien pour g�n�rer les projets Qt Creator (.pro) en Release.
Cliquer ensuite sur 'Ex�cuter CMake', puis, apr�s le d�roulement de CMake, cliquer sur 'Terminer' et le projet (.pro) se charge dans l'IDE.

----------------------------------------------------------------------
Note au sujet de l'activation/d�sactivation des composants avec CMake:
----------------------------------------------------------------------
- activation des composants: passer -DBUILD_component_nomducomposant=ON � CMake (exemple: -DBUILD_component_Curvature=ON)
- d�sactivation des composants: passer -DBUILD_component_nomducomposant=OFF � CMake (exemple: -DBUILD_component_Curvature=OFF)
