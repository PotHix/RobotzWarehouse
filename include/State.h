/*
 *
 * AnimSprite - By CrociDB
 * http://crocidb.wordpress.com/
 *
 * Obrigado por usar ^^
 *
 */

class State
{
private:
    int first;
    int last;
public:
    State(int f, int l);

    void SetFirstFrame(int f);
    void SetLastFrame(int l);

    int GetFirstFrame() const;
    int GetLastFrame() const;

    int GetNumFrames() const;
};
