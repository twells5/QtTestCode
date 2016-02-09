#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qwt.h"
#include "qwt_legend.h"
#include "qwt_plot_grid.h"
#include "qwt_plot_curve.h"
#include "qwt_symbol.h"
#include <QTimer>
#include <QDebug>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     ui->MyQwtPlot->setTitle( "MyTestPlot" );
     ui->MyQwtPlot->setCanvasBackground( Qt::white );
     ui->MyQwtPlot->setAxisScale( QwtPlot::yLeft, 0.0, 10.0);
     ui->MyQwtPlot->insertLegend( new QwtLegend() );
      QwtPlotGrid *grid = new QwtPlotGrid();
       grid->attach( ui->MyQwtPlot);

      QwtPlotCurve *curve = new QwtPlotCurve();
      curve->setTitle( "Pixel Count" );
      curve->setPen(QPen(Qt::blue));    //
      curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );

    //   QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
    //       QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 8, 8 ) );
    //   curve->setSymbol( symbol );



      QPolygonF points;
      points << QPointF( 0.0, 4.4 ) << QPointF( 1.0, 3.0 )
           << QPointF( 2.0, 4.5 ) << QPointF( 3.0, 6.8 )
           << QPointF( 4.0, 7.9 ) << QPointF( 5.0, 7.1 );
     //  curve->setSamples( points );
       curve->setData(points);

       curve->attach( ui->MyQwtPlot );

       ui->MyQwtPlot->resize( 600, 400 );

       cycle = 3;

       QTimer *timer = new QTimer(this);
       connect(timer, SIGNAL(timeout()), this, SLOT(updateChannelStatus()));
       timer->start(5000);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::updateChannelStatus()
{
    if(cycle % 3 == 0)
        ui->Ch1LE->setStyleSheet("background-color:green");
   else if(cycle % 3 == 1)
        ui->Ch1LE->setStyleSheet("background-color : yellow");
    else if(cycle % 3 == 2)
        ui->Ch1LE->setStyleSheet("background-color:red");

   cycle =  (cycle++) % 3;
}
