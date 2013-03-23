void init_ensemble(unsigned char *ensemble);

void ajoute(unsigned char *ensemble, int nb_to_add);

void affiche_ensemble(unsigned char *ensemble);

int appartient(int nb_searched, unsigned char *ensemble);

int cardinal(unsigned char *ensemble);

void unio(unsigned char *ensemble1, unsigned char *ensemble2);

void intersection(unsigned char *ensemble1, unsigned char *ensemble2);

void complementation(unsigned char *ensemble);
