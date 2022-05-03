#include "C_ArbreBinRech.h"

C_ArbreBinRech::C_ArbreBinRech()
{
	//racine = nullptr;
	taille = 0;
}

C_ArbreBinRech::~C_ArbreBinRech()
{
	//liberer(racine)
}

void C_ArbreBinRech::init(s_arbre_bin* pArbre)
{
	pArbre->racine = NULL;
}

void C_ArbreBinRech::parcPrefixe(s_noeud* racine)
{

	if (racine != nullptr) {

		traiter(racine);
		parcPrefixe(racine->fgauche);
		parcPrefixe(racine->fdroite);

	}

}

void C_ArbreBinRech::parcPostfixe(s_noeud* racine)
{

	if (racine != nullptr) {

		parcPostfixe(racine->fgauche);
		parcPostfixe(racine->fdroite);
		traiter(racine);

	}

}

void C_ArbreBinRech::traiter(s_noeud* n)
{

	//cout << n->n_donnee, ", ";
	printf("%d, ", n->n_donnee);

}

int C_ArbreBinRech::inserArbreVide(s_arbre_bin* pArbre, int n_val)
{
	
	s_noeud* elem = NULL;
	elem = (s_noeud*)malloc(sizeof(s_noeud));

	//Si l'élément est vide, ne rien retourner
	if (elem == NULL) {
		
		//cout << "L'arbre est vide" << endl;
		return 0;
	}
	else //dans le cas contraire, mettre en place l'abre
	{

		elem->n_donnee = n_val;

		elem->fgauche = NULL;
		elem->fdroite = NULL;
		pArbre->racine = elem;

		return 1;

	}

}

int C_ArbreBinRech::ajoutNoeuds(s_arbre_bin* pArbre, int n_val)
{
	
	s_noeud* elem = NULL;
	elem = (s_noeud*)malloc(sizeof(s_noeud));
	
	//
	s_noeud* courant = pArbre->racine;
	s_noeud* precedent = NULL;

	elem->fdroite = NULL;
	elem->fgauche = NULL;
	elem->n_donnee = n_val;

	//Pour trouver une place
	while (courant)
	{
		precedent = courant;
		if (elem->n_donnee < courant->n_donnee) {
			courant = courant->fgauche;
		}
		else
		{
			courant = courant->fdroite;
		}

	}

	//Celle-ci trouvée
	//precedent pointe vers le parent de notre noeud à remplacer.
	if (elem->n_donnee < precedent->n_donnee)
	{
		precedent->fgauche = elem;

	}
	else
	{
		precedent->fdroite = elem;
	}
	
	
	return 1;
}


//V1 de suppNoeud, mais soucis de logique pour continuer sur cette lancé
/*int C_ArbreBinRech::suppNoeud(s_arbre_bin* pArbre ,int n_val)
{

	auto ret = rechercheNoeud(pArbre->racine, n_val);

	//Arbre vide
	if (ret == NULL) {
		return -1;
	}

	//Si la taille correspond à 1
	if (taille == 1) {
		auto tmp = pArbre->racine;
		pArbre->racine = nullptr;
		delete tmp;
		taille--;
		return 0;

	}

	//Si les sous-branche droite et gauche sont NULL
	if (n_val < (*ret)->n_donnee)
	{
		//ne peux pas fonctionner
		(*ret)->fgauche = suppNoeud(pArbre, ret->fgauche, n_val);

	}

	//Si les sous-branches sont différent de NULL

	return 0;
}*/




// V1 recherche noeud
s_noeud* C_ArbreBinRech::recherche(s_arbre_bin* pArbre ,int n_val)
{
	return *rechercheNoeud(pArbre->racine,n_val);
}

s_noeud** C_ArbreBinRech::rechercheNoeud(s_noeud*& n, int n_val) const
{
	if (!n)	{
		//Arbre vide
		return NULL;
	}
	else if ((n->n_donnee) == n_val) {
		//La valeur recherchée est stockée dans la racine
		return &n;
	}
	else if (n_val < (n->n_donnee)) {
		//La valeur recherchée est stockée dans le sous-arbre gauche
		return rechercheNoeud(n->fgauche, n_val);
	}
	else {
		//Sinon, la valeur recherchée est stockée dans le sous-arbre droit
		return rechercheNoeud(n->fdroite, n_val);
	}

}

s_noeud* C_ArbreBinRech::suppNoeud(s_arbre_bin* pArbre, s_noeud* courant, int n_val)
{
	
	if (courant == nullptr) {
		//Arbre vide
		return courant;
	}
	else if(n_val < courant->n_donnee) {
		//Si n_val < donnée du noeur courant sous-arbre G
		courant->fgauche = suppNoeud(pArbre, courant->fgauche, n_val);

	}
	else if(n_val > courant->n_donnee) {
		//Si n_val > donnée du noeur courant sous-arbre D
		courant->fdroite = suppNoeud(pArbre, courant->fdroite, n_val);
	}
	else
	{
		if (courant->fgauche == nullptr) { //si enfant gauche = nullptr
			return courant->fdroite;
		}
		else if (courant->fdroite == nullptr) { //si enfant droit = nullptr
			return courant->fgauche;
				
		}
		else {
			//si enfant G et D sont différent de nullptr
			s_noeud* succ = plusGrand(courant->fgauche);
			if (courant != nullptr) {
				courant->n_donnee = succ->n_donnee; //remplacement de la valeur à supprimer par le successeur
				suppNoeud(pArbre, courant->fgauche, succ->n_donnee); //on supprime par recusivité la valeur doublon du successeur
			}
		}

	}
	
	
	return nullptr;
}

void C_ArbreBinRech::suppNoeudArbre(s_arbre_bin* pArbre, int n_val)
{

	assert(pArbre);
	if (pArbre->racine) {
		suppNoeud(pArbre, pArbre->racine, n_val);
	}

}

s_noeud* C_ArbreBinRech::plusGrand(s_noeud* elem)
{
	s_noeud* courant = elem;
	if (elem->fdroite == nullptr) {
		return courant;
	}

	return plusGrand(courant->fdroite);
}



//V2 fonction rechercheNeoud
/*
s_noeud* C_ArbreBinRech::rechercheNoeud(s_noeud*& n, int n_val) const
{
	cout << "entrée dans la fonction rechercherNoeud" << endl;

	if (!n) {
		//Arbre vide
		return NULL;

	}
	else if ((n->n_donnee) == n_val) {
		//La valeur recherchée est stockée dans la racine
		return n;
	}
	else if (n_val < (n->n_donnee)) {
		//La valeur recherchée est stockée dans le sous-arbre gauche
		return rechercheNoeud(n->fgauche, n_val);
	}
	else {
		//Sinon, la valeur recherchée est stockée dans le sous-arbre droit
		return rechercheNoeud(n->fdroite, n_val);
	}
}*/