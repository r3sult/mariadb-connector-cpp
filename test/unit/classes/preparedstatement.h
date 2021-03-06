/*
Copyright (c) 2009, 2011, Oracle and/or its affiliates. All rights reserved.

The MariaDB Connector/C++ is licensed under the terms of the GPLv2
<http://www.gnu.org/licenses/old-licenses/gpl-2.0.html>, like most
MariaDB Connectors. There are special exceptions to the terms and
conditions of the GPLv2 as it is applied to this software, see the
FLOSS License Exception
<http://www.mysql.com/about/legal/licensing/foss-exception.html>.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published
by the Free Software Foundation; version 2 of the License.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA
*/



#include "../unit_fixture.h"
#include <iostream>
#include <climits>

/**
 * Example of a collection of tests
 *
 */

namespace testsuite
{
namespace classes
{

class preparedstatement : public unit_fixture
{
private:
  typedef unit_fixture super;
  bool createSP(std::string sp_code);

public:

  EXAMPLE_TEST_FIXTURE(preparedstatement)
  {
    TEST_CASE(crash);
    TEST_CASE(anonymousSelect);
    TEST_CASE(InsertSelectAllTypes);
    TEST_CASE(assortedSetType);
    TEST_CASE(setNull);
    TEST_CASE(checkClosed);
    TEST_CASE(getMetaData);
    TEST_CASE(callSP);
    TEST_CASE(callSPInOut);
    TEST_CASE(callSPWithPS);
    TEST_CASE(callSPMultiRes);
    TEST_CASE(getWarnings);
    TEST_CASE(blob);
    TEST_CASE(executeQuery);
  }

  /**
   * SELECT ' ', NULL as string
   */
  void anonymousSelect();

  /**
   * Loops over all kinds of column types and inserts/fetches a value
   */
  void InsertSelectAllTypes();

  /**
   * Loops over assorted column types and uses setXYZ to insert a value
   */
  void assortedSetType();

  /**
   * Loops over assorted column types and uses setXYZ to insert a value
   */
  void setNull();

  /**
   * Calling close()
   */
  void checkClosed();

  /**
   * Compare PS and Non-PS Metadata.
   */
  void getMetaData();

  /**
   * Calls a stored procedure
   */
  void callSP();

  /**
   * Calls a stored procedure with IN and OUT parameters
   */
  void callSPInOut();

  /**
   * Calls a stored procedure which contains a prepared statement
   */
  void callSPWithPS();

  /**
   * Calls a stored procedure which returns multiple result sets
   */
  void callSPMultiRes();

  /**
   * TODO - temporary to isolate a crash, remove after fix!
   */
  void crash();

  /**
   * Check get|clearWarnings()
   */
  void getWarnings();

  /**
   * Check BLOB/LOB handling
   */
  void blob();

  /**
   * Check executeQuery() and invalid fetch mode
   *
   * TODO - the test does focus on code coverage not functionality
   */
  void executeQuery();


};

REGISTER_FIXTURE(preparedstatement);
} /* namespace classes */
} /* namespace testsuite */
