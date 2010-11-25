///////////////////////////////////////////////////////////////////////////
// Author: Martial TOLA
// Year: 2010
// CNRS-Lyon, LIRIS UMR 5205
///////////////////////////////////////////////////////////////////////////

Marche � suivre pour Mepp sous Mac OS X ('10.5 Leopard'* ou '10.6 Snow Leopard') :
----------------------------------------------------------------------------------

1) installer Xcode:
http://developer.apple.com/technologies/xcode.html

2) installer MacPorts:
http://www.macports.org/install.php

3) mettre � jour MacPorts: 
sudo port -v selfupdate

4) installer les paquets suivants avec MacPorts: 
sudo port install cgal						(assez long, <= 1 heure)
sudo port install qt4-mac					(tr�s long, environ 2-3 heures)
sudo port install libQGLViewer				(tr�s rapide, quelques minutes)
sudo port install glew						(tr�s tr�s rapide, quelques secondes)

5) t�l�charger les sources de Mepp:
svn checkout https://nom-du-d�veloppeur@scm.gforge.liris.cnrs.fr/svnroot/mepp/trunk

6a) compiler Mepp avec CMake et Makefile:
se positionner dans trunk, puis,
 - mkdir build; cd build
 - pour une version Release: cmake .. -DCMAKE_C_FLAGS='-arch x86_64' puis make
 - pour une version Debug: cmake .. -DCMAKE_C_FLAGS='-arch x86_64' -DCMAKE_BUILD_TYPE=Debug (2 fois pour la prise en compte du mode Debug) puis make
note: vous pouvez �galement utiliser la version "graphique" de CMake: cmake-gui

ou

6b) compiler Mepp avec CMake et Qt Creator:
CMake (ou CMake-gui) est capable de g�n�rer (pour le moment) des Makefiles Unix ainsi que des projets Code::Blocks ou encore KDevelop,
mais malheureusement pas encore des projets Qt Creator (.pro).
Qt Creator sait par contre interpr�ter directement le CMakeLists.txt de cmake
pour g�n�rer les projets Qt Creator (.pro).

Donc, pour g�n�rer les projets Qt Creator (.pro), voici la marche � suivre au sein de Qt Creator:

Ouvrir un fichier et choisir en bas 'Fichier de projet CMake'
puis choisir le CMakeLists.txt de la racine du trunk puis cliquer sur 'suivant'
puis dans 'Arguments' mettre -DCMAKE_C_FLAGS="-arch x86_64" -DCMAKE_BUILD_TYPE=Debug pour g�n�rer les projets Qt Creator (.pro) en Debug
ou -DCMAKE_C_FLAGS="-arch x86_64" pour g�n�rer les projets Qt Creator (.pro) en Release.
Renseigner si besoin le chemin pour CMake: /opt/local/bin/cmake 
Cliquer ensuite sur 'Ex�cuter CMake', puis, apr�s le d�roulement de CMake, cliquer sur 'Terminer' et le projet (.pro) se charge dans l'IDE.

----------------------------------------------------------------------
Note au sujet de l'activation/d�sactivation des composants avec CMake:
----------------------------------------------------------------------
- activation des composants: passer -DBUILD_component_nomducomposant=ON � CMake (exemple: -DBUILD_component_Curvature=ON)
- d�sactivation des composants: passer -DBUILD_component_nomducomposant=OFF � CMake (exemple: -DBUILD_component_Curvature=OFF)

---------------------------------------------------------------
Note au sujet de la g�n�ration d'un bundle portable (mepp.app):
---------------------------------------------------------------
"make install" permet de d�ployer un bundle portable sur un autre syst�me Mac, le bundle g�n�r� se trouve dans le dossier mepp_deploy



* Sous Mac OS X 10.5 Leopard, gcc 4 contient un bug lors de la compilation optimis�e d'une application avec la librairie CGAL,
il faut donc utiliser gcc 4.2 � la place:
cmake .. -DCMAKE_CXX_COMPILER=/usr/bin/g++-4.2 -DCMAKE_C_COMPILER=/usr/bin/gcc-4.2

De plus, si votre processeur ne supporte pas le 64 bits, il faut �galement passer -DCMAKE_C_FLAGS='-arch i386'
