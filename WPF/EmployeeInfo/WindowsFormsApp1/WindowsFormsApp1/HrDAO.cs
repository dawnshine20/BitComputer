using System;
using System.Collections.Generic;
using System.Data;
using System.Windows.Forms;
using Oracle.ManagedDataAccess.Client;

namespace WindowsFormsApp1
{
    class HrDAO
    {
        private string connectionString;
        private static readonly HrDAO instance = new HrDAO();

        private HrDAO()
        {
            connectionString = Properties.Settings.Default.ConnectionString;
        }
        public static HrDAO Instance
        {
            get
            {
                return instance;
            }
        }

        public Employee getEmployee(long id)
        {
            Employee employee = new Employee();
            string sql =
                "SELECT EMPLOYEE_ID, FIRST_NAME, LAST_NAME, EMAIL" +
                ", PHONE_NUMBER, HIRE_DATE, JOB_ID, SALARY, COMMISSION_PCT" +
                ", MANAGER_ID, DEPARTMENT_ID FROM EMPLOYEES WHERE EMPLOYEE_ID = :EMPLOYEE_ID";

            try
            {
                using (OracleConnection conn = new OracleConnection(connectionString))
                {
                    OracleCommand cmd = new OracleCommand(sql, conn)
                    { CommandType = CommandType.Text, BindByName = true };
                    cmd.Parameters.Add(":EMPLOYEE_ID", OracleDbType.Long).Value = id;
                    conn.Open();

                    using (OracleDataReader reader = cmd.ExecuteReader(CommandBehavior.SingleRow))
                    {
                        if (reader.Read())
                        {
                            employee.Employee_id = reader.GetInt64(0);
                            employee.First_name = reader.GetString(1);
                            employee.Last_name = reader.GetString(2);
                            employee.Email = reader.GetString(3);
                            employee.Phone_number = reader.GetString(4);
                            employee.Hire_date = reader.GetDateTime(5);
                            employee.Job_id = reader.GetString(6);
                            employee.Salary = reader.GetDouble(7);
                            employee.Commission_pct = reader.IsDBNull(8) ? 0.0 : reader.GetDouble(8);
                            employee.Manager_id = reader.IsDBNull(9) ? 0 : reader.GetInt64(9);
                            employee.Department_id = reader.IsDBNull(10) ? 0 : reader.GetInt32(10);

                            }
                    }
                }
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            
            return employee;
        }

        public ICollection<Employee> getEmployeeList()
        {
            ICollection<Employee> empList = new List<Employee>();
            try
            {
                using (OracleConnection conn = new OracleConnection(connectionString))
                {
                    OracleCommand cmd = conn.CreateCommand();
                    cmd.CommandType = CommandType.TableDirect; // 테이블 전체 데이터를 불러온다.
                    cmd.CommandText = "Employees";
                    conn.Open();

                    using (OracleDataReader reader = cmd.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            Employee employee = new Employee();
                            employee.Employee_id = reader.GetInt64(0);
                            employee.First_name = reader.GetString(1);
                            employee.Last_name = reader.GetString(2);
                            employee.Email = reader.GetString(3);
                            employee.Phone_number = reader.GetString(4);
                            employee.Hire_date = reader.GetDateTime(5);
                            employee.Job_id = reader.GetString(6);
                            employee.Salary = reader.GetDouble(7);
                            employee.Commission_pct = reader.IsDBNull(8) ? 0.0 : reader.GetDouble(8);
                            employee.Manager_id = reader.IsDBNull(9) ? 0 : reader.GetInt64(9);
                            employee.Department_id = reader.IsDBNull(10) ? 0 : reader.GetInt32(10);

                            empList.Add(employee);
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            
            return empList;
        }

        public ICollection<DataMapper> getHistory(int empNo)
        {
            DataTable dt = new DataTable();
            ICollection<DataMapper> listMapper = new List<DataMapper>();
            try
            {
                using (OracleConnection conn = new OracleConnection(connectionString))
                {
                    OracleCommand cmd = conn.CreateCommand();
                    cmd.CommandType = CommandType.StoredProcedure; // 함수 단위로 실행한다.(함수문 어디에 있는지 찾아낼것)
                    cmd.CommandText = "CURSOR_PKG.SP_JOB_HISTORY";
                    cmd.Parameters.Add(new OracleParameter("IN_EMPLOYEE_ID", OracleDbType.Int32, 
                        empNo, System.Data.ParameterDirection.Input));
                    cmd.Parameters.Add(new OracleParameter("OUT_CURSOR", OracleDbType.RefCursor,
                        System.Data.ParameterDirection.Output));
                    cmd.Connection = conn;

                    OracleDataAdapter oracleAdapter = new OracleDataAdapter(cmd);
                    oracleAdapter.Fill(dt);
                    if(dt.Rows.Count > 0)
                    {
                        foreach(DataRow row in dt.Rows)
                        {
                            DataMapper mapper = new DataMapper();
                            mapper.StringValue1 = row[0].ToString();
                            mapper.StringValue2 = row[1].ToString();

                            DateTime.TryParse(row[2].ToString(), out DateTime dateTime);
                            mapper.DateTimeValue1 = dateTime;

                            DateTime.TryParse(row[3].ToString(), out dateTime);
                            mapper.DateTimeValue2 = dateTime;

                            listMapper.Add(mapper);
                        }
                    }
                    else
                    {
                        MessageBox.Show("데이터가 없습니다.");
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            return listMapper;
        }

        public DataSet getInfo()
        {
            DataSet dataSet = new DataSet();

            try
            {
                using (OracleConnection conn = new OracleConnection(connectionString))
                {
                    OracleCommand cmd = conn.CreateCommand();
                    cmd.CommandType = CommandType.TableDirect;
                    cmd.CommandText = "Locations";
                    cmd.Connection = conn;

                    OracleDataAdapter oracleAdapter = new OracleDataAdapter(cmd);
                    oracleAdapter.Fill(dataSet, "Locations");

                    cmd.CommandText = "Jobs";
                    oracleAdapter.Fill(dataSet, "Jobs");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            return dataSet;
        }
    }
}
