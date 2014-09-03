#include "Sender.h"

Sender::Sender( const QString &portName,
                QSerialPort::BaudRate baudRate,
                QSerialPort::DataBits dataBits,
                QSerialPort::Parity parity,
                QSerialPort::StopBits stopBits,
                QSerialPort::FlowControl flowControl ) :
    m_serialPort( portName ),
    m_baudRate( baudRate ),
    m_dataBits( dataBits ),
    m_parity( parity ),
    m_stopBits( stopBits ),
    m_flowControl( flowControl )
{
}

Sender::~Sender()
{
    m_serialPort.close();
}

void Sender::open() throw( PortError )
{
    // Open the port
    if ( !m_serialPort.open( QIODevice::WriteOnly ) ) {
        throw PortError( "Error: unable to open the port \"" +
                         m_serialPort.portName().toStdString() + "\"" );
    }

    m_serialPort.setBaudRate( m_baudRate );
    m_serialPort.setDataBits( m_dataBits );
    m_serialPort.setParity( m_parity );
    m_serialPort.setStopBits( m_stopBits );
    m_serialPort.setFlowControl( m_flowControl );
}

void Sender::send( const QByteArray &data ) throw( PortError )
{
    if ( !m_serialPort.isOpen() ) {
        throw PortError( m_serialPort.errorString().toStdString() );
    }

    // Write data to the port
    if ( m_serialPort.write( data ) == -1 ) {
        throw PortError( m_serialPort.errorString().toStdString() );
    }
}
