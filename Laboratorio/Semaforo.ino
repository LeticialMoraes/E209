const int pinoVerde = 2;
const int pinoAmarelo = 3;
const int pinoVermelho = 4;

// Duração de cada estado em milissegundos
const unsigned long dumacaoVerde = 12000; // 12 segundos
const unsigned long duracaoAmarelo = 3000; // 3 segundos
const unsigned long duracaoVermelho = 15000; // 15 segundos

void setup(){

// Configunacão dos pinos como saida
  pinMode (pinoVende, OUTPUT);
  pinMode (pinoAmanelo, OUTPUT);
  pinMode (pinoVermelho, OUTPUT):
}

void loop() {
  // Estado Verde:
  digitalWrite(pinoVerde, HIGH);
  delay(duracaoVerde);
  digitalWrite(pinoVerde, LOW);

  // Estado Amarelo:
  digitalWrite(pinoAmarelo, HIGH);
  delay(duracaoAmarelo);
  digitalWrite(pinoAmarelo, LOW);

  // Estado Verde:
  digitalWrite(pinoVermelho, HIGH);
  delay(duracaoVermelho);
  digitalWrite(pinoVermelho, LOW);

}
