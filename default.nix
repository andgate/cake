with import <nixpkgs> {}; {
  testgameEnv = stdenv.mkDerivation {
    name = "testgame";
    buildInputs = [ stdenv cmake pkgconfig SDL2 SDL2_image SDL2_ttf SDL2_gfx SDL2_net ];
  };
}
