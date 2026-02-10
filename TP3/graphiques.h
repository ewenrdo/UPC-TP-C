/* Initialise la bibliothèque graphique et crée une fenêtre de la taille
   donnée. */
int gr_init(int width, int height);

/* Dessine un point aux coordonnées x et y de couleur (r,g,b).
   r, g et b sont compris entre 0 et 255. */
int gr_draw_point(int x, int y, int r, int g, int b);

/* Affiche la fenêtre et passe la main à la bibliothèque graphique. */
int gr_display(void);

