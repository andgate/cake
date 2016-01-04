with import <nixpkgs> {}; {
  cakeEnv = stdenv.mkDerivation {
    name = "cake";
    buildInputs = [ stdenv cmake pkgconfig sfml boost libyamlcpp ];
  };
}
