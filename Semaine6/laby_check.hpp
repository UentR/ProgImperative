#ifndef LABY_CHECK
#define LABY_CHECK

bool is_ant_tile(Tile t) {
    for ( auto tile: ant_tiles ) 
        if ( tile == t )
            return true;
    return false;
}

bool compare( Labyrinth labya, Labyrinth labyb ) {
    auto a = labya.view();
    auto b = labyb.view();
    if ( a.size() != b.size() )
        return false;
    for ( int i = 0; i < a.size(); i++) {
        if ( a[i].size() != b[i].size() )
            return false;
        for ( int j = 0 ; j < b[i].size(); j++ ) {
            if ( not is_ant_tile(a[i][j]) and not is_ant_tile(b[i][j]) and a[i][j] != b[i][j] )
                return false;
        }
    }
    return true;
}

bool a_obtenu(string s) {
    auto history = app->player.history;
    auto resultat = history[history.size()-1];
    auto attendu = Labyrinth(s);
    return compare(resultat, attendu);
}

#endif
