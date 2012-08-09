// Destroyer template based on John Vlissides article
// "To Kill a Singleton"

#ifndef DESTROYER_H
#define DESTROYER_H

template <class DOOMED> class Destroyer 
{
public:
    Destroyer(DOOMED* = 0);
    ~Destroyer();

    void SetDoomed(DOOMED*);
private:
    // Prevent users from making copies of a 
    // Destroyer to avoid double deletion:
    Destroyer(const Destroyer<DOOMED>&);
	void operator=(const Destroyer<DOOMED>&);
private:
    DOOMED* _doomed;
};

template <class DOOMED>
Destroyer<DOOMED>::Destroyer (DOOMED* d) {
    _doomed = d;
}

template <class DOOMED>
Destroyer<DOOMED>::~Destroyer () {
    delete _doomed;
}

template <class DOOMED>
void Destroyer<DOOMED>::SetDoomed (DOOMED* d) {
    _doomed = d;
}

#endif // DESTROYER_H
