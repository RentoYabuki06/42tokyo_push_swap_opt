#!/usr/bin/env python3
import subprocess
import random
import time
import argparse


def generate_random_numbers(n):
    """n個のユニークな乱数を生成"""
    return random.sample(range(-1000000, 1000000), n)


def run_push_swap(numbers):
    """push_swapを実行し、操作回数と結果を取得"""
    numbers_str = " ".join(map(str, numbers))
    try:
        # push_swapを実行し、操作内容を取得
        result = subprocess.run(f"./push_swap {numbers_str}", shell=True, capture_output=True, text=True, check=True)
        operations = result.stdout.strip()

        # checkerで結果を検証
        checker_cmd = f'ARG="{numbers_str}"; ./push_swap $ARG | ./checker $ARG'
        checker = subprocess.run(checker_cmd, shell=True, capture_output=True, text=True)
        is_valid = checker.stdout.strip() == "OK"

        if not is_valid:
            print(f"Warning: ソートに失敗 - 入力: {numbers_str}")
            print(f"Checker出力: {checker.stdout.strip()}")
            return None

        return len(operations.split("\n")) if operations else 0
    except subprocess.CalledProcessError as e:
        print(f"Error running push_swap: {e}")
        return None


def test_size(size, iterations):
    """指定されたサイズで複数回テストを実行"""
    operations = []
    failed_tests = 0

    print(f"\n=== {size}個の数字をテスト（{iterations}回）===")
    for i in range(iterations):
        numbers = generate_random_numbers(size)
        ops = run_push_swap(numbers)
        if ops is not None:
            operations.append(ops)
        else:
            failed_tests += 1
        if (i + 1) % 10 == 0:
            print(f"{i + 1}回完了...")

    if operations:
        success_rate = ((iterations - failed_tests) / iterations) * 100
        return min(operations), max(operations), sum(operations) / len(operations), success_rate
    return None, None, None, 0


def main():
    parser = argparse.ArgumentParser(description="push_swapのテストツール")
    parser.add_argument("-n", "--numbers", type=int, nargs="+", help="リストのサイズ（複数指定可能）例: -n 3 5 100 500")
    parser.add_argument(
        "-i", "--iterations", type=int, default=100, help="各サイズに対するテスト実行回数（デフォルト: 100）"
    )
    args = parser.parse_args()

    # デフォルトのテストケース
    if not args.numbers:
        test_cases = [(3, 100), (5, 100), (100, 100), (500, 100)]
    else:
        test_cases = [(size, args.iterations) for size in args.numbers]

    print(f"テスト実行回数: {args.iterations}")
    print("テストするリストのサイズ:", [size for size, _ in test_cases])

    for size, iterations in test_cases:
        min_ops, max_ops, avg_ops, success_rate = test_size(size, iterations)
        if min_ops is not None:
            print(f"\n{size}個の数字の結果:")
            print(f"成功率: {success_rate:.2f}%")
            print(f"最小操作回数: {min_ops}")
            print(f"最大操作回数: {max_ops}")
            print(f"平均操作回数: {avg_ops:.2f}")


if __name__ == "__main__":
    main()
