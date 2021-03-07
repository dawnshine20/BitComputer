using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Oracle.ManagedDataAccess.Client;

namespace DataCommandDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            //연결 객체
            OracleConnection connection = new OracleConnection();
            connection.ConnectionString = "Data Source=localhost:1521/orcl;User ID = c##lhb; Password=1234";

            connection.Open();

            //커맨드 객체
            OracleCommand command = new OracleCommand();
            command.Connection = connection;
            
            command.CommandText = "select count(*) from tab01";
            int count = (int)(decimal)command.ExecuteScalar();

            connection.Close();

            Console.WriteLine(count);
        }
    }
}
