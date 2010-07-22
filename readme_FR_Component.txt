///////////////////////////////////////////////////////////////////////////
// Author: Martial TOLA
// Year: 2010
// CNRS-Lyon, LIRIS UMR 5205
///////////////////////////////////////////////////////////////////////////

D�velopper un nouveau composant:
--------------------------------

1) s�inspirer de CGAL_Example dans trunk\src\components\Examples\CGAL_Example
(un renommage propre et pr�cis tenant compte de la ��case�� dans les .h, .hxx et .cpp devrait vous permettre d�obtenir tr�s facilement le squelette de votre composant)

2) le ��noyau�� de MEPP ne doit en principe pas �tre modifi�

3) votre composant doit avoir un nom en anglais (valid� par Florent) et doit �tre rattach� � une cat�gorie ci-dessous:

Analysis
Compression
Distance
Remeshing
Segmentation
Tools
Watermarking

ou �ventuellement

Examples

a) Ce nom doit �tre �galement le nom du sous-dossier (contenant le code source de votre composant) au sein de cette sous-cat�gorie sur le svn (cf. composant CGAL_Example).
b) Le nom de la classe C++ de ce composant doit �tre du type VotreComposant_Component (cf. composant CGAL_Example).
c) Le nom de la classe C++ du plugin (qui va de paire avec la classe ci-dessus) de votre composant doit �tre du type mepp_component_VotreComposant_plugin (cf. composant CGAL_Example).
Important: attention � la "case sensitive" pour ces 3 points.

A partir de l�, le script CMake s'occupe de tout, il n'y a pas � toucher une seule ligne de code du noyau de Mepp (ni le mepp_config.h.in, ni le polyhedron_enriched_polyhedron.h, ni le mainwindow.ui pour le menu).

Votre menu se d�clare en effet dans le fichier mepp_component_VotreComposant_plugin.hxx en le rattachant � la cat�gorie �voqu�e ci-dessus et en d�clarant les actions des menus comme ci-dessous (cf. composant CGAL_Example).

-----

public:
        mepp_component_CGAL_Example_plugin() : mepp_component_plugin_interface() {}
        ~mepp_component_CGAL_Example_plugin()
        {
            delete actionStep_1; delete actionStep_2; delete actionStep_3;
            delete actionStep_4;
        }

        void init(mainwindow* mainWindow, QList<QMdiSubWindow *> lw)
        {
            this->mw = mainWindow;
            this->lwindow = lw;
            this->mPluginName = this->metaObject()->className();
           
            // choice: menuTools, menuDistance_Quality_measure, menuAnalysis_Filtering, menuSegmentation, menuRemeshing_Subdivision,
            // menuCompression, menuWatermaking, menuExamples
            mParentMenu = mainWindow->menuExamples;

            // d�but --- actions ---
            actionStep_1 = new QAction(tr("Triangulate And Random Color Facets"), this);
            if (actionStep_1)
                connect(actionStep_1, SIGNAL(triggered()), this, SLOT(step1()));

            actionStep_2 = new QAction(tr("Create Center Vertex"), this);
            if (actionStep_2)
                connect(actionStep_2, SIGNAL(triggered()), this, SLOT(step2()));

            actionStep_3 = new QAction(tr("Show Black And White Facets"), this);
            if (actionStep_3)
                connect(actionStep_3, SIGNAL(triggered()), this, SLOT(step3()));

            actionStep_4 = new QAction(tr("Draw Connections"), this);
            if (actionStep_4)
                connect(actionStep_4, SIGNAL(triggered()), this, SLOT(step4()));
            // fin --- actions ---
        }

        QList<QAction*> actions() const
        {
            return QList<QAction*>()    //<< actionExample
                                        << actionStep_1
                                        << actionStep_2
                                        << actionStep_3
                                        << NULL
                                        << actionStep_4;
        }