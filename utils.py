from datetime import datetime
from typing import List

def get_date_times(dates: List[str]) -> List[datetime]:
    """
    Function that get a list of string dates and return the same list each date in datetime object.
    Each date string can be in following formats:
    1. <year>
    2. <year>-<month>
    3. <year>-<month>-<day>

    for example:
    >>> example_datetimes = ['2007', '2002-6', '2000-2-22']
    >>> get_date_times(example_datetimes)[0].strftime('%Y-%m-%d')
    '2007-01-01'

    >>> get_date_times(example_datetimes)[1].strftime('%Y-%m-%d')
    '2002-06-01'

    >>> get_date_times(example_datetimes)[2].strftime('%Y-%m-%d')
    '2000-02-22'

    """
    release_dates = []
    for release_date in dates:
        if len(release_date.split('-')) == 1:
            release_dates.append(datetime.strptime(release_date, '%Y'))
        elif len(release_date.split('-')) == 2:
            release_dates.append(datetime.strptime(release_date, '%Y-%m'))
        elif len(release_date.split('-')) == 3:
            release_dates.append(datetime.strptime(release_date, '%Y-%m-%d'))
        else:
            print(f"Cannot get datetime from {release_date}")
    return release_dates


def get_years(dates: List[str]) -> List[str]:
    """
    Function that get a list of string dates and return the same list each date only the year.
    Each date string can be in following formats:
    1. <year>
    2. <year>-<month>
    3. <year>-<month>-<day>

    for example:
    >>> example_datetimes = ['2007', '2002-6', '2000-2-22']
    >>> get_years(example_datetimes)[0]
    '2007'

    >>> get_years(example_datetimes)[1]
    '2002'

    >>> get_years(example_datetimes)[2]
    '2000'

    """
    release_dates = get_date_times(dates)
    return [str(year.year) for year in release_dates]


def apply_popularity(popularity: int) -> int:
    """
    This function apply popularity value to classification:

    if <= 70 popularity             - high popular      value: 2
    else if 40 <= popularity < 70   - medium popular    value: 1
    else, popularity < 40           - non popular       value: 0

    >>> apply_popularity(100)
    2

    >>> apply_popularity(70)
    2

    >>> apply_popularity(69)
    1

    >>> apply_popularity(40)
    1

    >>> apply_popularity(39)
    0

    >>> apply_popularity(0)
    0
    
    """
    if popularity >= 70:
        return 2
    elif popularity >= 40:
        return 1
    else:
        return 0


if __name__ == "__main__":
    import doctest

    (failures, tests) = doctest.testmod(report=True)
    print("{} failures, {} tests".format(failures, tests))
