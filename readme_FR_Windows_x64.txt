///////////////////////////////////////////////////////////////////////////
// Author: Martial TOLA
// Year: 2010
// CNRS-Lyon, LIRIS UMR 5205
///////////////////////////////////////////////////////////////////////////

Marche � suivre pour Mepp sous Windows (64 bits):
-------------------------------------------------


Note: vous devez disposer d'une machine 64 bits (Vista 64 bits ou Seven 64 bits)


1a) r�cup�rer et installer Visual Studio Express 2008 SP1:
http://download.gforge.liris.cnrs.fr/meppbin/windows/Visual_C++_2008_Express_with_SP1/VS2008ExpressWithSP1FRAx1504731.iso (869 Mo)

1b) r�cup�rer et installer MSDK for Windows 7 and .NET Framework 3.5 SP1:
http://download.gforge.liris.cnrs.fr/meppbin/windows/MSDK%20for%20Windows%207%20and%20.NET%20Framework%203.5%20SP1/GRMSDKX_EN_DVD_v7.iso (1.4 Go)

1c) activer le nouveau SDK:
menu "D�marrer" -> "Tous les programmes" -> "Microsoft Windows SDK v7.0" -> "CMD Shell",
puis taper "WindowsSdkVer.exe -version:v7.0"

---

2a) r�cup�rer les d�pendances du projet MEPP (headers & libs, CMake & CMake-gui):
http://download.gforge.liris.cnrs.fr/meppbin/windows/MEPP/mepp_cmake_dep_prebuilt_binaries_x64_v01.rar (567 Mo)
et d�compresser l'archive dans le r�pertoire de votre choix (exemple: C:\dev64)

2b) r�cup�rer les maj des d�pendances du projet MEPP (headers & libs, CMake & CMake-gui):
http://download.gforge.liris.cnrs.fr/meppbin/windows/MEPP/mepp_cmake_dep_prebuilt_binaries_x64_v01_patch_01.rar (100 Ko)
et d�compresser l'archive dans le m�me r�pertoire que celui de l'�tape 2a). R�pondre "oui" pour �craser le fichier "mpfr-vc90-mt-gd.dll".

2c) patcher la base de registre car par d�faut Visual Studio Express n'autorise pas la compilation 64 bits:
menu "D�marrer" -> "Tous les programmes" -> "Accessoires" -> bouton droit sur "Invite de commandes" puis "Ex�cuter en tant qu'administrateur" (important, sinon le script suivant �choue),
puis taper "cd C:\dev64\VCE64BIT_WIN7SDK" (si vous avez d�compress� le fichier ci-dessus dans C:\dev64),
puis taper "setup_x64.bat"

---

3) positionner 3 variables d�environnement�(menu ��Poste de travail�� -> bouton droit -> Propri�t�s -> onglet ��Avanc頻 -> bouton ��Variables d�environnement�� (en bas) -> puis dans la partie ��Variables syst�me�� (en bas):
 - bouton ��nouveau���: rajouter la variable QTDIR avec comme valeur�:
C:\dev64\Qt_4.6.3_x64 si vous avez d�compress� le fichier ci-dessus dans C:\dev64
 - bouton ��nouveau���: rajouter la variable CGAL_DIR avec comme valeur�:
C:\dev64\CGAL-3.6.1_x64 si vous avez d�compress� le fichier ci-dessus dans C:\dev64
 - bouton ��modifier���: rajouter au sein (� la fin par exemple) de la variable Path:
;C:\dev64\Qt_4.6.3_x64\bin (attention au ;)

4) t�l�charger les sources de Mepp:
Par exemple, dans C:/mepp/SVN,
avec TortoiseSVN (SVN Checkout...): https://nom-du-d�veloppeur@scm.gforge.liris.cnrs.fr/svnroot/mepp/trunk

5) utiliser CMake-gui (dans C:\dev64\_cmake-2.8.3-win32-x86_\bin)
 - renseigner le champ "Where is the source code" avec par exemple C:/mepp/SVN/trunk
 - renseigner le champ "Where to build the binaries" avec par exemple C:/mepp/SVN/trunk/build
 - cliquer sur Configure (en bas � gauche) et choisir comme Generator "Visual Studio 9 2008 Win64" (attention, ne pas se tromper avec ""Visual Studio 9 2008")
 - activer/d�sactiver les composants que vous d�sirez ou non (premi�res lignes en haut toujours du type BUILD_component_nomducomposant, exemple: BUILD_component_Curvature)
 - cliquer sur Configure (en bas � gauche) � nouveau
 - cliquer sur Generate (en bas � gauche)
 - ouvrir avec Visual Studio la solution mepp.sln g�n�r�e dans C:/mepp/SVN/trunk/build puis compiler Mepp
 - se positionner sur le "sous-projet" mepp, faire un "bouton droit" puis cliquer sur "D�finir comme projet de d�marrage"
