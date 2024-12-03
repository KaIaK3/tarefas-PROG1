// main.cpp

#include <QtCharts/QChartView>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QLineSeries>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtCore/QTimer>
#include <QtGui/QPainter>
#include <random>

QT_CHARTS_USE_NAMESPACE

const int NUMERO_DE_PONTOS = 10000; // Número total de pontos a serem gerados

class MonteCarloPi : public QMainWindow {
    Q_OBJECT

private:
    QChartView *chartView;
    QScatterSeries *insideSeries;
    QScatterSeries *outsideSeries;
    QLineSeries *circleSeries; // Série para desenhar o círculo
    QLineSeries *squareSeries; // Série para desenhar o quadrado
    QPushButton *startButton;
    QLabel *resultLabel;
    QTimer *timer;
    int pontosGerados;
    int pontosDentro;

public:
    MonteCarloPi() : QMainWindow(), pontosGerados(0), pontosDentro(0) {
        // Séries de pontos dentro e fora do círculo
        insideSeries = new QScatterSeries();
        insideSeries->setName("Dentro do Círculo");
        insideSeries->setMarkerSize(5.0);
        insideSeries->setColor(Qt::blue);

        outsideSeries = new QScatterSeries();
        outsideSeries->setName("Fora do Círculo");
        outsideSeries->setMarkerSize(5.0);
        outsideSeries->setColor(Qt::red);

        // Série para desenhar o círculo
        circleSeries = new QLineSeries();
        circleSeries->setName("Círculo");

        // Preencher a série com pontos de um círculo
        for (double t = 0; t <= 2 * M_PI; t += 0.01) {
            double x = cos(t);
            double y = sin(t);
            circleSeries->append(x, y);
        }

        // Série para desenhar o quadrado
        squareSeries = new QLineSeries();
        squareSeries->setName("Quadrado");

        // Definir os vértices do quadrado de lado 2, centrado na origem
        squareSeries->append(-1, -1);
        squareSeries->append(1, -1);
        squareSeries->append(1, 1);
        squareSeries->append(-1, 1);
        squareSeries->append(-1, -1); // Fechar o quadrado

        // Criação do gráfico
        QChart *chart = new QChart();
        chart->addSeries(insideSeries);
        chart->addSeries(outsideSeries);
        chart->addSeries(circleSeries);
        chart->addSeries(squareSeries);
        chart->setTitle("Método de Monte Carlo para Aproximação de Pi");
        chart->createDefaultAxes();
        chart->axes(Qt::Horizontal).first()->setRange(-1.0, 1.0);
        chart->axes(Qt::Vertical).first()->setRange(-1.0, 1.0);

        // Criação do QChartView
        chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // Criação do botão de início
        startButton = new QPushButton("Iniciar Simulação");

        // Criação do label para mostrar o resultado
        resultLabel = new QLabel("Aproximação de Pi: 0\nFórmula: Pi ≈ 4 * (Pontos dentro do círculo / Pontos totais)");

        // Configuração do layout
        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(chartView);
        layout->addWidget(resultLabel);
        layout->addWidget(startButton);

        QWidget *centralWidget = new QWidget();
        centralWidget->setLayout(layout);
        setCentralWidget(centralWidget);

        // Conexão do botão ao slot de início
        connect(startButton, &QPushButton::clicked, this, &MonteCarloPi::iniciarSimulacao);

        // Timer para gerar pontos iterativamente
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MonteCarloPi::gerarPontos);
    }

private slots:
    void iniciarSimulacao() {
        // Resetar os dados
        insideSeries->clear();
        outsideSeries->clear();
        pontosGerados = 0;
        pontosDentro = 0;

        // Desativar o botão para evitar múltiplas simulações simultâneas
        startButton->setEnabled(false);

        // Iniciar o timer para gerar pontos
        timer->start(1); // Gera pontos continuamente a cada .1ms
    }

    void gerarPontos() {
        if (pontosGerados >= NUMERO_DE_PONTOS) {
            // Simulação concluída
            timer->stop();
            startButton->setEnabled(true);

            // Exibe o resultado final
            double piEstimado = 4.0 * pontosDentro / pontosGerados;
            resultLabel->setText(QString("Aproximação de Pi: %1\nFórmula: Pi ≈ 4 * (Pontos dentro do círculo / Pontos totais)")
                                 .arg(piEstimado, 0, 'f', 6));
            return;
        }

        // Gerar um ponto aleatório
        std::random_device rd;
        std::default_random_engine generator(rd());
        std::uniform_real_distribution<double> distribution(-1.0, 1.0);

        double x = distribution(generator);
        double y = distribution(generator);

        // Verificar se o ponto está dentro do círculo
        if (x * x + y * y <= 1.0) {
            insideSeries->append(x, y);
            pontosDentro++;
        } else {
            outsideSeries->append(x, y);
        }

        pontosGerados++;

        // Atualiza o label com a estimativa de pi
        double piEstimado = 4.0 * pontosDentro / pontosGerados;
        resultLabel->setText(QString("Aproximação de Pi: %1\nFórmula: Pi ≈ 4 * (Pontos dentro do círculo / Pontos totais)")
                             .arg(piEstimado, 0, 'f', 6));
    };
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MonteCarloPi window;
    window.resize(480,360);
    window.setWindowTitle("Simulação de Monte Carlo para Pi");
    window.show();

    return app.exec();
}

#include "main.moc"

